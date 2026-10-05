CA1_WEIGHTAGE = 15
CA2_WEIGHTAGE = 15
PROJECT_WEIGHTAGE = 15
EXERCISES_WEIGHTAGE = 15
EXAM_WEIGHTAGE = 40

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


class Student:
    def __init__(self, last_name, first_name, student_id, points, max_points):
        self.last = last_name
        self.first = first_name
        self.student_id = student_id
        self.points = points
        self.max_points = max_points


def read_lines(filename):
    with open(filename, encoding="utf-8") as f:
        text = f.read()

    lines = text.split("\n")

    cleaned = []
    for i in lines:
        cleaned.append(i.strip())

    lines = cleaned

    result = []
    for i in lines:
        if i != "":
            result.append(i)
    return result


def read_max_marks_file(filename):
    lines = read_lines(filename)

    header = lines[0].split(";")

    max_total = 0
    for column in header[3:]:
        if column == "":
            continue
        max_total += float(column.split("/")[1])

    students = []
    for i in lines[1:]:
        parts = i.split(";")

        last_name = parts[0]
        first_name = parts[1]
        student_id = parts[2]

        points = 0
        for p in parts[3:]:
            if p != "":
                points += float(p)

        student = Student(last_name, first_name, student_id, points, max_total)
        students.append(student)

    return students


def read_groups_table(filename):
    table = []
    for i in read_lines(filename)[1:]:
        pair = i.split(";")[:2]
        table.append(pair)
    return table


def find_student(students, student_id):
    for s in students:
        if s.student_id == student_id:
            return s
    return None


def find_groups(table, key):
    for pair in table:
        if pair[0] == key:
            return pair[1]
    return None


def find_total_percentage(points, max_points, weightage):
    return points / max_points * weightage


def letter_grade(total):
    for minimum, letter in LETTER_GRADES:
        if total >= minimum:
            return letter
    return "F"


ca1 = read_max_marks_file("Grades CA 1.csv")
ca2 = read_max_marks_file("Grades CA 2.csv")
exercises = read_max_marks_file("Grades Exercises.csv")
exam = read_max_marks_file("Grades Final Exam.csv")
student_group = read_groups_table("Groups.csv")
group_grade = read_groups_table("Grades Groups.csv")


output = "Last name;First name;ID;CA 1;CA 2;Project;Exercises;Exam;Sum;Grade\n"

print(f"{'Last name':<12}{'First name':<12}{'ID':<9}{'CA 1':>7}{'CA 2':>7}"
      f"{'Project':>9}{'Exercises':>11}{'Exam':>7}{'Sum':>8}{'Grade':>7}")

for student in ca1:
    student_id = student.student_id
    last = student.last
    first = student.first

    ca2_student = find_student(ca2, student_id)
    ex_student = find_student(exercises, student_id)
    exam_student = find_student(exam, student_id)

    ca1_score = find_total_percentage(student.points, student.max_points, CA1_WEIGHTAGE)
    ca2_score = find_total_percentage(ca2_student.points, ca2_student.max_points, CA2_WEIGHTAGE)
    ex_score = find_total_percentage(ex_student.points, ex_student.max_points, EXERCISES_WEIGHTAGE)
    exam_score = find_total_percentage(exam_student.points, exam_student.max_points, EXAM_WEIGHTAGE)

    group = find_groups(student_group, student_id)
    project_raw = float(find_groups(group_grade, group))
    project_score = find_total_percentage(project_raw, 10, PROJECT_WEIGHTAGE)

    total = ca1_score + ca2_score + project_score + ex_score + exam_score
    total = round(total, 2)
    grade = letter_grade(total)

    output += (f"{last};{first};{student_id};{ca1_score:.2f};{ca2_score:.2f};"
               f"{project_score:.2f};{ex_score:.2f};{exam_score:.2f};{total:.2f};{grade}\n")

    print(f"{last:<12}{first:<12}{student_id:<9}{ca1_score:>7.2f}{ca2_score:>7.2f}"
          f"{project_score:>9.2f}{ex_score:>11.2f}{exam_score:>7.2f}{total:>8.2f}{grade:>7}")


with open("student_grades_results.csv", "w", encoding="utf-8") as f:
    f.write(output)

print("\nSaved to student_grades_results.csv")