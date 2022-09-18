import unittest
from stream_bms_data.sender.sensors.soc import State_Of_Charge

test_object = State_Of_Charge()


class Test_State_Of_Charge(unittest.TestCase):
    def test_state_of_charge(self):
        self.assertTrue(test_object.validate(30))
        self.assertFalse(test_object.validate(10))
        self.assertFalse(test_object.validate(90))


if __name__ == '__main__':
    unittest.main()
