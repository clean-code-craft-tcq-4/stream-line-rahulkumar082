import unittest
import stream_bms_data.receiver.receiver as Receiver


class Test_Sender(unittest.TestCase):
    def test_min_temp_and_soc(self):
        min_temp, min_soc = Receiver.min_temp_and_soc([[1,2],[3,4]])
        self.assertEqual(min_temp, 1)
        self.assertEqual(min_soc, 2)

    def test_max_temp_and_soc(self):
        max_temp, max_soc = Receiver.max_temp_and_soc([[1,2],[3,4]])
        self.assertEqual(max_temp, 3)
        self.assertEqual(max_soc, 4)

    def test_simple_moving_average(self):
        simple_moving_avg_temp, simple_moving_avg_soc = Receiver.calc_moving_average(5, [[1,2],[3,4],[5,6],[7,8],[9,10],[11,12]])
        self.assertEqual(simple_moving_avg_temp, 7)
        self.assertEqual(simple_moving_avg_soc, 8)


if __name__ == '__main__':
    unittest.main()
