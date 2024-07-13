import csv
import pandas as pd

def read_csv_file(file_path):
    values = []
    with open(file_path, 'r') as file:
        csv_reader = csv.reader(file)
        for row in csv_reader:
            values.extend(row)
    return values

file_path = 'dataset.csv'
all_values = read_csv_file(file_path)
# df = pd.DataFrame(all_values)
print(all_values)