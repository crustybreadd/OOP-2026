names = ["Liam", "Noah", "Oliver"]
ages = [30, 25, 35]

for i, (name, a) in enumerate(zip(names, ages)):
	print(f"{i}: {name} is {a}")
