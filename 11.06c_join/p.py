# list of strings, each string is a field from the second line of the CSV data
l = ['Smith', 'Liam', '3024498', '0.00', '2.00', '3.00', '0.00', '0.00', '0.00', '0.00'] 

s = ";".join(l) # join the list of strings l into a single string, using the semicolon character as the separator

print(s)
