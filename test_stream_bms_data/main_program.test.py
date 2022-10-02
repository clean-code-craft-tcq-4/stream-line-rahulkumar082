import subprocess
import unittest
import os

class Test_Receiver(unittest.TestCase):
    def test_main_program(self):
        output = os.popen('python ./stream_bms_data/sender/sender.py | python ./stream_bms_data/receiver/receiver.py').read()
        self.assertIsNotNone(output)

if __name__ == '__main__':
    unittest.main()