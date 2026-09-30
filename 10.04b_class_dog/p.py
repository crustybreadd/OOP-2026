class Dog:				# compound-statement header; class definition
	def bark(self):		# compound-statement header; method definition
		print("woof")	# statement
		print("woof")	# statement, same block
		print("woof")	# statement, same block

d = Dog();				# create object d of class Dog
d.bark()				# call bark() on object d
