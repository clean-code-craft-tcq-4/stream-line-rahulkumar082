import csv

def read_csv_format(csv_file):
    output = []
    with open(csv_file) as csv_read_file:
        csv_input = csv.reader(csv_read_file)
        for row in csv_input:
            output.append(','.join(row))
    return output