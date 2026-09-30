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

#F-->print_vars

print(f"var(s): {vars(s)}")

#<--F