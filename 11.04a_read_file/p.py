filename = "Grades CA 1.csv"

with open(filename, encoding="utf-8") as f:
	file_string = f.read()

print(file_string)