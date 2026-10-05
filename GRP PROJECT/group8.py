# Reads all the Moodle grade CSV files, combines them per student,
# and writes "group8.csv"


# How many percentage (out of 100) each part is worth in the final Sum
CA1_WEIGHTAGE = 15        # CA 1 counts for 15 percent
CA2_WEIGHTAGE = 15        # CA 2 counts for 15 percent
PROJECT_WEIGHTAGE = 15    # Project counts for 15 percent
EXERCISES_WEIGHTAGE = 15  # Exercises count for 15 percent
EXAM_WEIGHTAGE = 40       # Final exam counts for 40 percent

# The project grade in "Grades Groups.csv" is given out of 10
PROJECT_MAX_MARKS = 10

# Letter grade boundaries: if Sum >= the number, the student gets that letter
# The list goes from highest to lowest so the first match is the right one
LETTER_GRADES = [
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


# STUDENT CLASS

class Student:
    # Constructor: runs every time we create a new Student object
    # __init__ is a special method that Python calls automatically when we create a new object
    # self is a reference to the object being created; it allows us to store data in the object
    def __init__(self, last_name, first_name, student_id, points, max_points):
        self.last = last_name           # last name, e.g. "Wilson"
        self.first = first_name         # first name, e.g. "Noah"
        self.student_id = student_id    # student ID, e.g. "3024512"
        self.points = points            # marks the student got, e.g. 5.0
        self.max_points = max_points    # marks the test is out of, e.g. 21.0


# REUSEABLE FUNCTIONS

def read_lines(filename):
    # Open the file for reading; "with" closes it automatically afterwards
    with open(filename, encoding="utf-8") as f:

        # Read the whole file into one long string
        text = f.read()

    # This line splits on "\n", which is the newline character
    lines = text.split("\n")

    # creating a new list to hold the cleaned lines
    cleaned = []

    # This goes through every line in the list and cleans off invisible characters, like \r and spaces
    for i in lines:

        # for each line, strip off whitespace and carriage returns, and add it to the cleaned list
        cleaned.append(i.strip())

    # Replace the old list with the cleaned list
    lines = cleaned

    # Throw away empty lines (a blank line at the very end of the file)
    result = [] 
    for i in lines:
        if i != "":
            result.append(i)
    return result


def read_max_marks_file(filename):
    # Get all lines of the file as a list
    lines = read_lines(filename)

    # Splits the first element of the list (the header) into a list of column names
    header = lines[0].split(";")

    # Find the maximum possible score by looking at the header columns
    # create a variable to hold the maximum total score
    max_total = 0

    # Start at column 3, because columns 0-2 are e.g Last name, First name, ID, ...
    for column in header[3:]:

        # ; characters are already gone which leaves us with empty columns, e.g. ";;;;" becomes ["", "", "", ""]
        # So we skip those
        if column == "":
            continue

        # "Q. 1 /2.00" split on "/" gives ["Q. 1 ", "2.00"]; take the number
        # [1] is the second element of the list, which is the maximum score for that question
        max_total += float(column.split("/")[1])

    # Empty list to store one Student object per student
    students = []

    # Go through every line except the header (lines[1:] skips line 0)
    for i in lines[1:]:

        # Split the line into its separate values and store them in a list called "parts"
        parts = i.split(";")

        # Take the first three values: last name, first name, ID
        last_name = parts[0]
        first_name = parts[1]
        student_id = parts[2]

        # Add up the points of all questions (skip empty columns "" and the first three columns)
        points = 0
        for p in parts[3:]:
            if p != "":
                points += float(p)

        # Create a Student object with this student's names, ID, points and maximum points
        student = Student(last_name, first_name, student_id, points, max_total)

        # Add the Student object to the end of the list
        students.append(student)

    # Give the list of students back to whoever called this function
    return students


def read_groups_table(filename):
    # Reads a two-column file like "ID;Group" or "Group;Grade /10"
    # and returns a list of pairs, e.g. [["3024498", "1"], ["3024512", "1"], ...]
    table = []
    # Skip the header line with [1:]
    for i in read_lines(filename)[1:]:
        # Split "3024498;1" into ["3024498", "1"] and keep only the first two values
        pair = i.split(";")[:2]
        # Add the pair to the end of the list
        table.append(pair)
    return table


def find_student(students, student_id):
    # Go through the list of Student objects one by one
    for s in students:
        # Stop and give back the student whose ID matches
        if s.student_id == student_id:
            return s
    # No student with that ID was found
    return None


def find_groups(table, key):
    # Go through the list of pairs one by one
    for pair in table:
        # pair[0] is the first column, pair[1] is the second column
        if pair[0] == key:
            return pair[1]
    # No pair with that key was found
    return None


def find_percentage_achieved(points, max_points):
    # Turn raw points into a percentage out of 100.
    # Example: 5 out of 21 points  ->  5 / 21 * 100 = 23.81
    return points / max_points * 100


def find_total_percentage(points, max_points, weightage):
    # Turn raw points into weighted points.
    # Example: 5 out of 21 points, weight 15  ->  5 / 21 * 15 = 3.57
    return points / max_points * weightage 


def letter_grade(total):
    # Check each boundary from the top (A+) down
    for minimum, letter in LETTER_GRADES:
        # The first boundary the student reaches decides the letter
        if total >= minimum:
            return letter
    # Safety net (only reached if total is negative)
    return "F"


# READ ALL THE FILES


ca1 = read_max_marks_file("Grades CA 1.csv")              # list of Students with CA 1 points
ca2 = read_max_marks_file("Grades CA 2.csv")              # list of Students with CA 2 points
exercises = read_max_marks_file("Grades Exercises.csv")   # list of Students with Exercise points
exam = read_max_marks_file("Grades Final Exam.csv")       # list of Students with Exam points
student_group = read_groups_table("Groups.csv")          # list of [ID, group number] pairs
group_grade = read_groups_table("Grades Groups.csv")     # list of [group number, grade out of 10] pairs


# CALCULATE EACH STUDENT'S RESULT


# Header line of the output file, in the order required by the project notes
# The header is built from several short strings so it is easier to read; Python joins them together
output = ("Last name;First name;ID;"                                                                             # student details
          "CA 1 Total marks;CA 1 Percentage achieved;CA 1 Percentage normalized to 15%;"                         # 3 CA 1 columns
          "CA 2 Total marks;CA 2 Percentage achieved;CA 2 Percentage normalized to 15%;"                         # 3 CA 2 columns
          "Exercises Total marks;Exercises Percentage achieved;Exercises Percentage normalized to 15%;"          # 3 Exercises columns
          "Project Group;Project Total marks;Project Percentage achieved;Project Percentage normalized to 15%;"   # group + 3 Project columns
          "Final Exam Total marks;Final Exam Percentage achieved;Final Exam Percentage normalized to 40%;"       # 3 Final Exam columns
          "Total percentage;Overall grade\n")                                                                   # final result; "\n" starts a new line

# Print the header row of the on-screen table, with all 21 columns
# Short names are used so the table fits on the screen:
# "Mk" = total marks, "%" = percentage achieved, "/15" or "/40" = normalized percentage
# ":<11" means left-align in an 11-character wide column, ":>8" means right-align in 8 characters
print(f"{'Last name':<11}{'First name':<11}{'ID':<9}"            # student details
      f"{'CA1 Mk':>8}{'CA1 %':>8}{'CA1/15':>8}"                 # CA 1 columns
      f"{'CA2 Mk':>8}{'CA2 %':>8}{'CA2/15':>8}"                 # CA 2 columns
      f"{'Ex Mk':>8}{'Ex %':>8}{'Ex/15':>8}"                    # Exercises columns
      f"{'Grp':>5}{'Prj Mk':>8}{'Prj %':>8}{'Prj/15':>8}"       # Project columns
      f"{'Exam Mk':>9}{'Exam %':>8}{'Exam/40':>9}"              # Final Exam columns
      f"{'Total':>8}{'Grade':>7}")                              # final result

# Loop over every Student object in the CA 1 list (same order as the CSV files)
for student in ca1:
    # Get this student's ID and name from the CA 1 file
    student_id = student.student_id
    last = student.last
    first = student.first

    # Find the same student in the other lists by matching the ID
    ca2_student = find_student(ca2, student_id)
    ex_student = find_student(exercises, student_id)
    exam_student = find_student(exam, student_id)

    # CA 1: percentage out of 100, e.g. 5 / 21 * 100 = 23.81
    ca1_percent = find_percentage_achieved(student.points, student.max_points)
    # Scale CA 1 points to its weight (out of 15)
    ca1_score = find_total_percentage(student.points, student.max_points, CA1_WEIGHTAGE)

    # CA 2: percentage out of 100, e.g. 11 / 16 * 100 = 68.75
    ca2_percent = find_percentage_achieved(ca2_student.points, ca2_student.max_points)
    # Scale CA 2 points to its weight (out of 15)
    ca2_score = find_total_percentage(ca2_student.points, ca2_student.max_points, CA2_WEIGHTAGE)

    # Exercises: percentage out of 100
    ex_percent = find_percentage_achieved(ex_student.points, ex_student.max_points)
    # Scale exercise points to its weight (out of 15)
    ex_score = find_total_percentage(ex_student.points, ex_student.max_points, EXERCISES_WEIGHTAGE)

    # Final Exam: percentage out of 100
    exam_percent = find_percentage_achieved(exam_student.points, exam_student.max_points)
    # Scale exam points to its weight (out of 40)
    exam_score = find_total_percentage(exam_student.points, exam_student.max_points, EXAM_WEIGHTAGE)

    # Find which group this student is in, e.g. "1"
    group = find_groups(student_group, student_id)
    # Look up that group's project grade (out of 10) and turn it into a number
    project_raw = float(find_groups(group_grade, group))
    # Project: percentage out of 100, e.g. 8 / 10 * 100 = 80.00
    project_percent = find_percentage_achieved(project_raw, PROJECT_MAX_MARKS)
    # Scale the project grade to its weight (out of 15)
    project_score = find_total_percentage(project_raw, PROJECT_MAX_MARKS, PROJECT_WEIGHTAGE)

    # Add all five parts together to get the total out of 100
    total = ca1_score + ca2_score + project_score + ex_score + exam_score
    # Round to 2 decimals first, so the letter matches the number we show
    total = round(total, 2)
    # Turn the total into a letter grade like "B+"
    grade = letter_grade(total)

    # Add one line to the output text; ":.2f" means "show 2 decimal places"
    # Each assessment gets 3 columns: total marks, percentage achieved, normalized percentage
    output += (f"{last};{first};{student_id};"                                                # name and ID
               f"{student.points:.2f};{ca1_percent:.2f};{ca1_score:.2f};"                      # CA 1: marks, %, out of 15
               f"{ca2_student.points:.2f};{ca2_percent:.2f};{ca2_score:.2f};"                  # CA 2: marks, %, out of 15
               f"{ex_student.points:.2f};{ex_percent:.2f};{ex_score:.2f};"                     # Exercises: marks, %, out of 15
               f"{group};{project_raw:.2f};{project_percent:.2f};{project_score:.2f};"         # Project: group, marks, %, out of 15
               f"{exam_student.points:.2f};{exam_percent:.2f};{exam_score:.2f};"               # Final Exam: marks, %, out of 40
               f"{total:.2f};{grade}\n")                                                        # total out of 100 and letter grade

    # Print this student as one row of the on-screen table, with the same widths as the header
    # ":.2f" means show 2 decimal places
    print(f"{last:<11}{first:<11}{student_id:<9}"                                               # student details
          f"{student.points:>8.2f}{ca1_percent:>8.2f}{ca1_score:>8.2f}"                         # CA 1
          f"{ca2_student.points:>8.2f}{ca2_percent:>8.2f}{ca2_score:>8.2f}"                     # CA 2
          f"{ex_student.points:>8.2f}{ex_percent:>8.2f}{ex_score:>8.2f}"                        # Exercises
          f"{group:>5}{project_raw:>8.2f}{project_percent:>8.2f}{project_score:>8.2f}"          # Project
          f"{exam_student.points:>9.2f}{exam_percent:>8.2f}{exam_score:>9.2f}"                  # Final Exam
          f"{total:>8.2f}{grade:>7}")                                                           # total and grade


# WRITE THE RESULTS FILE


# Open (or create) "group8.csv" for writing ("w" overwrites an old file)
with open("group8.csv", "w", encoding="utf-8") as f:
    # Write all the text we built up into the file
    f.write(output)

# Tell the user we are done
print("\nSaved to group8.csv")
