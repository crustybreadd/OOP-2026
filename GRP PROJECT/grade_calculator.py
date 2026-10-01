# grades.py
# Reads all the Moodle grade CSV files, combines them per student,
# and writes "results.csv" with the same columns as the example table:
# Last name;First name;ID;CA 1;CA 2;Project;Exercises;Exam;Sum;Grade


# ---------------------------------------------------------------
# 1. SETTINGS  (change these if your lecturer gives other numbers)
# ---------------------------------------------------------------

# How many points (out of 100) each part is worth in the final Sum.
WEIGHTS = {
    "CA 1": 15,        # CA 1 counts for 15 points
    "CA 2": 15,        # CA 2 counts for 15 points
    "Project": 20,     # Project counts for 20 points
    "Exercises": 15,   # Exercises count for 15 points
    "Exam": 35,        # Final exam counts for 35 points
}

# Letter grade boundaries: if Sum >= the number, the student gets that letter.
# The list goes from highest to lowest so the first match is the right one.
# ASSUMPTION: a common scale that also matches the example (70.81 -> B+).
GRADE_SCALE = [
    (85, "A+"),
    (80, "A"),
    (75, "A-"),
    (70, "B+"),
    (65, "B"),
    (60, "B-"),
    (55, "C+"),
    (50, "C"),
    (45, "D+"),
    (40, "D"),
    (0,  "F"),
]


# ---------------------------------------------------------------
# 2. HELPER FUNCTIONS
# ---------------------------------------------------------------

def read_lines(filename):
    # Open the file for reading; "with" closes it automatically afterwards
    with open(filename, encoding="utf-8") as f:
        # Read the whole file into one long string
        text = f.read()
    # Cut the string into a list of lines, one line per row of the file
    lines = text.split("\n")
    # Remove "\r" and spaces at the end of each line (Windows line endings)
    lines = [line.strip() for line in lines]
    # Throw away empty lines (e.g. a blank line at the very end of the file)
    return [line for line in lines if line != ""]


def read_question_file(filename):
    # Get all lines of the file as a list
    lines = read_lines(filename)
    # The first line is the header, e.g. "Last name;First name;ID;Q. 1 /2.00;..."
    header = lines[0].split(";")

    # Find the maximum possible score by looking at the header columns
    max_total = 0
    # Start at column 3, because columns 0-2 are Last name, First name, ID
    for column in header[3:]:
        # Some files have empty extra columns ";;;;" - skip those
        if column == "":
            continue
        # "Q. 1 /2.00" split on "/" gives ["Q. 1 ", "2.00"]; take the number
        max_total += float(column.split("/")[1])

    # Dictionary to store the results: key = student ID, value = student info
    students = {}
    # Go through every line except the header (lines[1:] skips line 0)
    for line in lines[1:]:
        # Split the line into its separate values
        parts = line.split(";")
        # Take the first three values: last name, first name, ID
        last_name, first_name, student_id = parts[0], parts[1], parts[2]
        # Add up the points of all questions (skip empty columns)
        points = sum(float(p) for p in parts[3:] if p != "")
        # Save this student's names, points, and the maximum points
        students[student_id] = {
            "last": last_name,
            "first": first_name,
            "points": points,
            "max": max_total,
        }
    # Give the dictionary back to whoever called this function
    return students


def read_simple_table(filename):
    # Reads a two-column file like "ID;Group" or "Group;Grade /10"
    # and returns a dictionary {first column: second column}
    table = {}
    # Skip the header line with [1:]
    for line in read_lines(filename)[1:]:
        # Split "3024498;1" into "3024498" and "1"
        key, value = line.split(";")[:2]
        # Store it in the dictionary
        table[key] = value
    return table


def scale(points, max_points, weight):
    # Turn raw points into weighted points.
    # Example: 6 out of 10 points, weight 20  ->  6 / 10 * 20 = 12.0
    return points / max_points * weight


def letter_grade(total):
    # Check each boundary from the top (A+) down
    for minimum, letter in GRADE_SCALE:
        # The first boundary the student reaches decides the letter
        if total >= minimum:
            return letter
    # Safety net (only reached if total is negative)
    return "F"


# ---------------------------------------------------------------
# 3. READ ALL THE FILES
# ---------------------------------------------------------------

ca1 = read_question_file("Grades CA 1.csv")              # CA 1 points per student
ca2 = read_question_file("Grades CA 2.csv")              # CA 2 points per student
exercises = read_question_file("Grades Exercises.csv")   # Exercise points per student
exam = read_question_file("Grades Final Exam.csv")       # Exam points per student
student_group = read_simple_table("Groups.csv")          # ID -> group number
group_grade = read_simple_table("Grades Groups.csv")     # group number -> grade out of 10


# ---------------------------------------------------------------
# 4. CALCULATE EACH STUDENT'S RESULT
# ---------------------------------------------------------------

# Header line of the output file, same order as the example table
output = "Last name;First name;ID;CA 1;CA 2;Project;Exercises;Exam;Sum;Grade\n"

# Also print a neat table on the screen.
# ":<12" means "left-align in a 12-character wide column", ":>7" means right-align.
print(f"{'Last name':<12}{'First name':<12}{'ID':<9}{'CA 1':>7}{'CA 2':>7}"
      f"{'Project':>9}{'Exercises':>11}{'Exam':>7}{'Sum':>8}{'Grade':>7}")

# Loop over every student ID in the CA 1 file (same order as the CSV files)
for student_id in ca1:
    # Get this student's name from the CA 1 file
    last = ca1[student_id]["last"]
    first = ca1[student_id]["first"]

    # Scale CA 1 points to its weight (out of 15)
    ca1_score = scale(ca1[student_id]["points"], ca1[student_id]["max"], WEIGHTS["CA 1"])
    # Scale CA 2 points to its weight (out of 15)
    ca2_score = scale(ca2[student_id]["points"], ca2[student_id]["max"], WEIGHTS["CA 2"])
    # Scale exercise points to its weight (out of 15)
    ex_score = scale(exercises[student_id]["points"], exercises[student_id]["max"], WEIGHTS["Exercises"])
    # Scale exam points to its weight (out of 35)
    exam_score = scale(exam[student_id]["points"], exam[student_id]["max"], WEIGHTS["Exam"])

    # Find which group this student is in, e.g. "1"
    group = student_group[student_id]
    # Look up that group's project grade (out of 10) and turn it into a number
    project_raw = float(group_grade[group])
    # Scale the project grade to its weight (out of 20)
    project_score = scale(project_raw, 10, WEIGHTS["Project"])

    # Add all five parts together to get the total out of 100
    total = ca1_score + ca2_score + project_score + ex_score + exam_score
    # Round to 2 decimals first, so the letter matches the number we show
    total = round(total, 2)
    # Turn the total into a letter grade like "B+"
    grade = letter_grade(total)

    # Add one line to the output text; ":.2f" means "show 2 decimal places"
    output += (f"{last};{first};{student_id};{ca1_score:.2f};{ca2_score:.2f};"
               f"{project_score:.2f};{ex_score:.2f};{exam_score:.2f};{total:.2f};{grade}\n")

    # Print the same student as one row of the on-screen table
    print(f"{last:<12}{first:<12}{student_id:<9}{ca1_score:>7.2f}{ca2_score:>7.2f}"
          f"{project_score:>9.2f}{ex_score:>11.2f}{exam_score:>7.2f}{total:>8.2f}{grade:>7}")


# ---------------------------------------------------------------
# 5. WRITE THE RESULTS FILE
# ---------------------------------------------------------------

# Open (or create) "results.csv" for writing ("w" overwrites an old file)
with open("results.csv", "w", encoding="utf-8") as f:
    # Write all the text we built up into the file
    f.write(output)

# Tell the user we are done
print("\nSaved to results.csv")