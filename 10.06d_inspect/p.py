import inspect

class Song:
	type = "Media"							# class variable

	def __init__(self, name, duration):		# constructor
		self.name = name					# instance attribute
		self.duration = duration

	def print(self):
		"""prints the song"""				# documentation
		print(f"{self.name} ({int(self.duration/60):02d}:" + 
				f"{self.duration%60:02d})")

s = Song("My Song", 123)


print(inspect.signature(Song.print))	# (self)
print(inspect.getdoc(Song.print))		# 'prints the song'
print(inspect.getsource(Song.print))	# source code of print
print(inspect.isfunction(Song.print))	# True
print(inspect.isfunction(s.print))		# False
print(inspect.ismethod(Song.print))		# False
print(inspect.ismethod(s.print))		# True
print(s.print.__func__ is Song.print)	# True
print(s.print.__self__ is s) 			# True
