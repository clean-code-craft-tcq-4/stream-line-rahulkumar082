import random
from venv import create
from stream_bms_data.sender.sensors.temperature import Temperature
from stream_bms_data.sender.sensors.soc import State_Of_Charge

def create_fifty_valid_random_ranges_for_sensors(sensor_class1, sensor_class2):
    clubbed_sensors_data = []
    sensor1_min, sensor1_max  = sensor_class1().min_value, sensor_class1().max_value
    sensor2_min, sensor2_max  = sensor_class2().min_value, sensor_class2().max_value
    for row_count in range(50):
        clubbed_sensors_data.append([random.randint(sensor1_min+1, sensor1_max-1), random.randint(sensor2_min+1, sensor2_max-1)])
    return (clubbed_sensors_data)

create_fifty_valid_random_ranges_for_sensors(Temperature, State_Of_Charge)