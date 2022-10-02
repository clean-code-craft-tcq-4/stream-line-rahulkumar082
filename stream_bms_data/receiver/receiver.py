import json
import sys


def read_parameters_from_console():
    console_input = sys.stdin.read()
    return(console_input)

def is_lesser(current_min_val, candidate_val):
    if (current_min_val >= candidate_val):
        return candidate_val
    return current_min_val

def is_greater(current_max_val, candidate_val):
    if (current_max_val <= candidate_val):
        return candidate_val
    return current_max_val

def min_temp_and_soc(csv_sensor_data):
    min_temp, min_soc = csv_sensor_data[0][0], csv_sensor_data[0][1]
    for list_element in csv_sensor_data:
        min_temp = is_lesser(min_temp, list_element[0])
        min_soc = is_lesser(min_soc, list_element[1])
    return (min_temp, min_soc)

def max_temp_and_soc(csv_sensor_data):
    max_temp, max_soc = csv_sensor_data[0][0], csv_sensor_data[0][1]
    for list_element in csv_sensor_data:
        max_temp = is_greater(max_temp, list_element[0])
        max_soc = is_greater(max_soc, list_element[1])
    return (max_temp, max_soc)

def calc_moving_average(number_of_last_elements, csv_sensor_data):
    last_elements_list = csv_sensor_data[-number_of_last_elements:]
    simple_moving_avg_temp = 0
    simple_moving_avg_soc = 0
    for elements in last_elements_list:
        simple_moving_avg_temp += elements[0]
        simple_moving_avg_soc += elements[1]
    simple_moving_avg_temp /= number_of_last_elements
    simple_moving_avg_soc /= number_of_last_elements
    return (simple_moving_avg_temp, simple_moving_avg_soc)

if __name__ == '__main__':
    data = read_parameters_from_console()
    csv_sensor_data = json.loads(data)
    min_temp, min_soc = min_temp_and_soc(csv_sensor_data=csv_sensor_data)
    max_temp, max_soc = max_temp_and_soc(csv_sensor_data=csv_sensor_data)
    moving_avg = calc_moving_average(5, csv_sensor_data=csv_sensor_data)
    print("Min Temp Sensor Data: \t\t", min_temp)
    print("Min SoC Sensor Data: \t\t", min_soc)
    print("Max Temp Sensor Data: \t\t", max_temp)
    print("Max SoC Sensor Data: \t\t", max_soc)
    print("Moving Sensor Data: \t\t", moving_avg)