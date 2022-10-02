from helper_scripts.csv.write_csv import write_csv_file
from helper_scripts.csv.random_valid_range import create_fifty_valid_random_ranges_for_sensors
from stream_bms_data.sender.sensors.soc import State_Of_Charge
from stream_bms_data.sender.sensors.temperature import Temperature


def create_input_csv_for_sender():
    temperature_sensor_class = Temperature
    soc_sensor_class = State_Of_Charge
    combined_sensors_data = create_fifty_valid_random_ranges_for_sensors(temperature_sensor_class, soc_sensor_class)
    csv_file = "./stream_bms_data/sender/csv_input.csv"
    write_csv_file(csv_file, combined_sensors_data)

create_input_csv_for_sender()
