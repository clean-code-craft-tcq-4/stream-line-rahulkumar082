import csv


def write_csv_file(csv_file, csv_text):
    with open(csv_file, 'w') as csv_file_write:
        writer = csv.writer(csv_file_write)
        for row in csv_text:
            writer.writerow(row)
