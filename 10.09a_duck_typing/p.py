class Duck:
	def quack(self):
		return "Quack"

class Dog:
	def quack(self):
		return "Woof... no, quack!"

def make_it_quack(thing):
	return thing.quack()	# no isinstance check needed

make_it_quack(Duck())		# Quack
make_it_quack(Dog())		# Woof... no, quack!