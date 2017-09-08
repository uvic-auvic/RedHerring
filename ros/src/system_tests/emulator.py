
import pty
import os

class DeviceEmulator:
    def __init__(self):
        self.master, slave = pty.openpty()
        self.port = os.ttyname(slave)
        os.write(master, 'con\n')

    def write(self, data):
        os.write(self.master, data)

    def read(self, buffer=1000):
        data = ''
        while not data: # block
            data = os.read(self.master, buffer)
        return data
