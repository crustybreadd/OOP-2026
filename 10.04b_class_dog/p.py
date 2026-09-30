class Dog:				# compound-statement header; class definition
	def bark(self):		# compound-statement header; method definition
		print("woof")	# statement
		print("woof")	# statement, same block
		print("woof")	# statement, same block

	def bark2(self):
		print("meow")

	def bark3(self):
		a = "hello" 	# this creates a LOCAL variable named "a", scoped to bark3() only
		self.b = "bye" 	# attribute
		c = [1, "lol" , 1.5]
		print(a)		# read the LOCAL variable correctly
		print(self.b)	# read the ATTRIBUTE correctly
		print(id(a)) 	# id() prints the address of the variable
		print(type(c)) 	# check the variable type in this case c is a list
		print(type(c[2]))
		c.append("beek")# append the list and add the string
		print(c)
class Bird:
	def toot(self):
		print("toot")

def sound(x):
	x.sound()

d = Dog();				# create object d of class Dog, ';' not required
d.bark()				# call bark() on object d
d.bark2()
d.bark3()
sound(Bird())

# indentation is important in python
# self is equivalent of this in C++/C
# def means define a function/method