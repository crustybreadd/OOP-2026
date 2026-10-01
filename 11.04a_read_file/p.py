filename = "Groups.csv"  # replace with your file name

with open(filename, encoding="utf-8") as f: # open the file and save the file object as f
	file_string = f.read() # read the entire file into a string

print(file_string)