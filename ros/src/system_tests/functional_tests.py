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


def process_handler(stdoutQueue, device_class):
    sys.stdout = StreamWriter(stdoutQueue)
    a = device_class()
    a.start()


class ProcessManager:
    def __init__(self):
        self.manager = multiprocessing.Manager()
        self.stdout = self.manager.Queue()
        self.get_process_list()
    
    def get_device_class(self):
        warnings.filterwarnings('error') # So that we can catch runtime warnings
        directory = os.path.dirname(os.path.abspath(__file__))
        full_path_contents = [os.path.join(directory, x) for x in os.listdir(directory)]
        device_folders = [x for x in full_path_contents if os.path.isdir(x)]
        for dev_dir in device_folders:
            device = os.path.basename(os.path.normpath(dev_dir))
            module_name = '{0}.{0}'.format(device)
            try:
                module = importlib.import_module(module_name)
            except RuntimeWarning, e:
                raise FunctionalTestError(e.args[0])
            device_class = getattr(module, device)
            yield device_class
                
    def get_process_list(self):
        self.processes = []
        for device in self.get_device_class():
            self.processes.append(device)
        self.unfinished_processes = len(self.processes)

    def process_finished(self, results):
        if self.unfinished_processes > 0:
            self.unfinished_processes -= 1

    def start(self):
        self.pool = multiprocessing.Pool(processes=len(self.processes))
        workers = [self.pool.apply_async(process_handler, args=(self.stdout, process), callback=self.process_finished) for process in self.processes]
        while self.unfinished_processes > 0:
            try:
                print self.stdout.get_nowait()
            except Queue.Empty:
                pass
        self.pool.close()
        while True: # Clean up anything left in the buffer after the process has ended
            try:
                print self.stdout.get_nowait()
            except Queue.Empty:
                break
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