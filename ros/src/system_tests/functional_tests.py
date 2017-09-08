from time import sleep
import multiprocessing
import Queue
import pty
import sys
import os


def getRosDirectories():
    directory = os.path.dirname(os.getcwd())
    ros_node_path = [os.path.join(directory, x) for x in os.listdir(directory)]
    return [x for x in ros_node_path if os.path.isdir(x)]

if __name__ == '__main__':
    # print getRosDirectories()
    manager = multiprocessing.Manager()
    stdout = manager.Queue()
    processes = 1
    pool = multiprocessing.Pool(processes=processes)
    [pool.apply_async(startSerialDevice, (str(x), stdout)) for x in range(processes)]
    while True:
        try:
            print stdout.get_nowait()
        except Queue.Empty:
            pass
        except KeyboardInterrupt:
            pool.terminate()
            break
    pool.join()       