import os

class launchfile_creator(object):
    param_start = '##PARAM_'
    paramt_end = '_##'
    def __init__(self):
        self.getFileContents()
        self.parseForParameters()
        

    def getFileContents(self, launchfile_name='template_launch_file.launch'):
        fpath = os.path.dirname(__file__)
        full_path = os.path.join(fpath, launchfile_name)
        with open(full_path) as f:
            self.raw_contents = f.read()

    def parseForParameters(self):
        print self.raw_contents.format(motor_controller='test')


if __name__ == '__main__':
    launch = launchfile_creator()