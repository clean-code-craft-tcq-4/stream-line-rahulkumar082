from stream_bms_data.sender.sensors.soc import State_Of_Charge
from stream_bms_data.sender.sensors.temperature import Temperature
from helper_scripts.csv.read_csv import read_csv_format


csv_file = "stream_bms_data/sender/csv_input.csv"
csv_data = read_csv_format(csv_file=csv_file)


def verify_csv_data_with_sensors():
    verified_csv_data = []
    for csv_input in csv_data:
        temperature_value, soc_value = int(csv_input.split(',')[0]), int(csv_input.split(',')[1])
        is_temp_ok = check_if_sensor_okay(Temperature, temperature_value)
        is_soc_ok = check_if_sensor_okay(State_Of_Charge, soc_value)
        verified_csv_data.append([is_temp_ok, is_soc_ok])
    console_print(verified_csv_data)
    return (verified_csv_data)

def check_if_sensor_okay(sensor_class, value):
    return value if sensor_class().validate(value) else False

def console_print(verified_csv_data):
    print(verified_csv_data)
