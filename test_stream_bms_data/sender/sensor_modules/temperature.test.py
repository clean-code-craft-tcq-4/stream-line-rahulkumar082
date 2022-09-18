import unittest
from stream_bms_data.sender.sensors.temperature import Temperature

test_object = Temperature()


class Test_Temperature(unittest.TestCase):
    def test_temperature(self):
        self.assertTrue(test_object.validate(20))
        self.assertFalse(test_object.validate(1))
        self.assertFalse(test_object.validate(50))


if __name__ == '__main__':
    unittest.main()
