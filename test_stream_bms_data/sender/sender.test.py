import unittest
from stream_bms_data.sender.sender import verify_csv_data_with_sensors


class Test_Sender(unittest.TestCase):
    def test_ability_to_run_sensor(self):
        csv_data = verify_csv_data_with_sensors()
        self.assertNotEqual(csv_data, [])

    def test_correctness_of_csv_data(self):
        csv_data = verify_csv_data_with_sensors()
        self.assertTrue(verify_no_false_values_in_list(csv_data))

def verify_no_false_values_in_list(list_of_values):
    flag = False
    for row in list_of_values:
        flag = match_value_in_a_row(flag, row)
    return flag

def match_value_in_a_row(value, row):
    if value in row:
        return False
    return True


if __name__ == '__main__':
    unittest.main()
