from time import sleep
import multiprocessing
import warnings
import imp
import importlib
import Queue
import sys
import os

class FunctionalTestError(Exception):
    def __init__(self, message):
        Exception.__init__(self, message)


class StreamWriter:
    def __init__(self, stdout):
        self.stdout = stdout

    def write(self, data):
        if data.strip():
            self.stdout.put(data.rstrip())

    def flush(self):
        pass


def process_handler(device_class, stdoutQueue, paramQueue):
    sys.stdout = StreamWriter(stdoutQueue)
    a = device_class()
    paramQueue.put((device_class, a.getParameters()))
    a.start()


class ProcessManager:
    def __init__(self):
        self.manager = multiprocessing.Manager()
        self.stdout = self.manager.Queue()
        self.params = self.manager.Queue()
        self.get_devices_list()
    
    def get_device_class(self, ros_node_directory = 'ros_nodes'):
        warnings.filterwarnings('error') # So that we can catch runtime warnings
        directory = os.path.dirname(os.path.abspath(__file__))
        node_directory = os.path.join(directory, ros_node_directory)
        full_path_contents = [os.path.join(node_directory, x) for x in os.listdir(node_directory)]
        device_folders = [x for x in full_path_contents if os.path.isdir(x)]
        for dev_dir in device_folders:
            device = os.path.basename(os.path.normpath(dev_dir))
            module_name = '{0}.{1}.{1}'.format(ros_node_directory, device)
            try:
                module = importlib.import_module(module_name)
            except RuntimeWarning, e:
                raise FunctionalTestError(e.args[0])
            yield getattr(module, device) # Will only work if the class name is same as the directory

    def get_devices_list(self):
        self.devices = {}
        for device in self.get_device_class():
            self.devices[device] = None
        self.unfinished_processes = len(self.devices)

    def process_finished(self, results):
        if self.unfinished_processes > 0:
            self.unfinished_processes -= 1

    def waiting_for_all_devices(self):
        for device_param in self.devices.itervalues():
            if device_param is None:
                return True
        return False

    def wait_for_device_init(self):
        while self.waiting_for_all_devices():
            try:
                device, params = self.params.get_nowait()
                self.devices[device] = params
            except Queue.Empty:
                pass  
        
    def start_print_loop(self):
        """Just loops and prints anything placed in the shared queue"""
        while self.unfinished_processes > 0:
            try:
                print self.stdout.get_nowait()
            except Queue.Empty:
                pass
        # Should only get here if all our workers have finished working
        # Which is never the case, so should never get here
        self.pool.close() 

    def empty_print_buffer(self):
        """Clean up anything left in the buffer after all processes have ended"""
        while True:
            try:
                print self.stdout.get_nowait()
            except Queue.Empty:
                break

    def start(self):
        self.pool = multiprocessing.Pool(processes=len(self.devices))        
        workers = [self.pool.apply_async(process_handler, args=(device, self.stdout, self.params), callback=self.process_finished) for device in self.devices]
        self.wait_for_device_init()
        self.start_print_loop() # In most cases, we will never break out of here
        self.empty_print_buffer()
        self.pool.join()

    def terminate(self):
        if self.pool:
            self.pool.terminate()
            self.pool.join()


if __name__ == '__main__':
    manager = ProcessManager()
    try:
        manager.start()
    except KeyboardInterrupt:
        manager.terminate()   