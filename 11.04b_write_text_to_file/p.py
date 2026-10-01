filename = "results.csv" # create a new file called results.csv

s = "Last name;First name;ID;CA 1;CA 2;Project;Exercises;Exam;Sum;Grade\n" # header line
s += "Smith;Liam;3024498;7.35;15.00;12.00;13.25;23.21;70.81;B+\n" # data line
s += "Wilson;Noah;3024512;9.43;11.20;12.32;14.31;23.45;56.71;C+\n" # data line

with open(filename, "w", encoding="utf-8") as f:
	f.write(s) # write the string s to the file