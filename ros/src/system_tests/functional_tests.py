from time import sleep
import multiprocessing
import Queue
import sys
import os

# def getRosDirectories():
    # directory = os.getcwd()
    # folder_contents = [os.path.join(directory, x) for x in os.listdir(os.getcwd())]
    # return [x for x in folder_contents if os.path.isdir(x)]


class StreamWriter:
    def __init__(self, stdout):
        self.stdout = stdout

    def write(self, data):
        if data.strip():
            self.stdout.put(data.rstrip())

    def flush(self):
        pass


def a_loop():
    i = 0
    while i < 3:
        i += 1
        print i
        sleep(1)


def process_handler(stdoutQueue, executing_function):
    sys.stdout = StreamWriter(stdoutQueue)
    executing_function()


class ProcessManager:
    def __init__(self):
        self.manager = multiprocessing.Manager()
        self.stdout = self.manager.Queue()
        self.getProcesses()
    
    def getProcesses(self):
        self.processes = []
        # Do stuff
        for i in range(2):
            self.processes.append(a_loop)
        # Do stuff
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
        self.pool.join()

    def terminate(self):
        if self.pool:
            self.pool.terminate()
            self.pool.join()


if __name__ == '__main__':
    # print getRosDirectories()
    manager = ProcessManager()
    try:
        manager.start()
    except KeyboardInterrupt:
        manager.terminate()   