s = """Last name;First name;ID;Q. 1 /2.00;Q. 2 /2.00;Q. 3 /3.00;Q. 4 /2.00;Q. 5 /4.00;Q. 6 /3.00;Q. 7 /5.00
Smith;Liam;3024498;0.00;2.00;3.00;0.00;0.00;0.00;0.00
Wilson;Noah;3024512;0.00;2.00;3.00;0.00;0.00;0.00;0.00
Williams;Oliver;3024513;0.00;2.00;3.00;0.00;0.00;0.00;0.00"""

l = s.split("\n")
print(l)

print(f"Length: {len(l)}")
print(f"l[1]: {l[1]}")

print(l[1].split(";"))