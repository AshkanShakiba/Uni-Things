CREATE TABLE Students
(
    student_id NUMERIC,
    student_name VARCHAR(32) NOT NULL,
    student_email VARCHAR(32) UNIQUE,
    student_major VARCHAR(32),
    PRIMARY KEY (student_id)
);

CREATE TABLE Courses
(
    course_id NUMERIC,
    course_name VARCHAR(32),
    course_description VARCHAR(256),
    course_credit_hours NUMERIC,
    PRIMARY KEY (course_id)
);

CREATE TABLE Enrollments
(
    enrollment_id NUMERIC,
    student_id NUMERIC,
    course_id NUMERIC,
    enrollment_grade NUMERIC,
    PRIMARY KEY (enrollment_id),
    FOREIGN KEY (student_id) REFERENCES Students(student_id),
    FOREIGN KEY (course_id) REFERENCES Courses(course_id)
);

CREATE TABLE Instructors
(
    instructor_id NUMERIC,
    instructor_name VARCHAR(32),
    instructor_email VARCHAR(32),
    instructor_department VARCHAR(32),
    PRIMARY KEY (instructor_id)
);

CREATE TABLE Departments
(
    department_id NUMERIC,
    department_name VARCHAR(32) NOT NULL,
    department_chair NUMERIC,
    PRIMARY KEY (department_id),
    FOREIGN KEY (department_chair) REFERENCES Instructors(instructor_id) 
);


INSERT INTO Students (student_id, student_name, student_email, student_major) VALUES (1, 'Anakin Skywalker', 'anakin@starwars.com', 'M1');
INSERT INTO Students (student_id, student_name, student_email, student_major) VALUES (2, 'Armin Arlert', 'armin@shingekinokyojin.com', 'M2');
INSERT INTO Students (student_id, student_name, student_email, student_major) VALUES (3, 'Barry Allen', 'barry@flash.com', 'M3');
INSERT INTO Students (student_id, student_name, student_email, student_major) VALUES (4, 'Peter Parker', 'peter@spidey.com', 'M4');
INSERT INTO Students (student_id, student_name, student_email, student_major) VALUES (5, 'Light Yagami', 'light@deathnote.com', 'M5');

INSERT INTO Courses (course_id, course_name, course_description, course_credit_hours) VALUES (1, 'C1', '...', 1);
INSERT INTO Courses (course_id, course_name, course_description, course_credit_hours) VALUES (2, 'C2', '...', 2);
INSERT INTO Courses (course_id, course_name, course_description, course_credit_hours) VALUES (3, 'C3', '...', 3);
INSERT INTO Courses (course_id, course_name, course_description, course_credit_hours) VALUES (4, 'C4', '...', 4);
INSERT INTO Courses (course_id, course_name, course_description, course_credit_hours) VALUES (5, 'C5', '...', 5);

INSERT INTO Enrollments (enrollment_id, student_id, course_id, enrollment_grade) VALUES (1, 1, 1, 'A');
INSERT INTO Enrollments (enrollment_id, student_id, course_id, enrollment_grade) VALUES (2, 2, 2, 'B');
INSERT INTO Enrollments (enrollment_id, student_id, course_id, enrollment_grade) VALUES (3, 3, 3, 'C');
INSERT INTO Enrollments (enrollment_id, student_id, course_id, enrollment_grade) VALUES (4, 4, 4, 'D');
INSERT INTO Enrollments (enrollment_id, student_id, course_id, enrollment_grade) VALUES (5, 5, 5, 'D');

INSERT INTO Instructors (instructor_id, instructor_name, instructor_email, instructor_department) VALUES (1, 'Obi-Wan Kenobi', 'kenobi@starwars.com', 'D1');
INSERT INTO Instructors (instructor_id, instructor_name, instructor_email, instructor_department) VALUES (2, 'Erwin Smith', 'smith@shingekinokyojin.com', 'D2');
INSERT INTO Instructors (instructor_id, instructor_name, instructor_email, instructor_department) VALUES (3, 'Harrison Wells', 'wells@flash.com', 'D3');
INSERT INTO Instructors (instructor_id, instructor_name, instructor_email, instructor_department) VALUES (4, 'Tony Stark', 'stark@marvel.com', 'D4');
INSERT INTO Instructors (instructor_id, instructor_name, instructor_email, instructor_department) VALUES (5, 'Ryuk', 'ryunk@deathnote.com', 'D5');

INSERT INTO Departments (department_id, department_name, department_chair) VALUES (1, 'D1', 1);
INSERT INTO Departments (department_ID, department_Name, department_Chair) VALUES (2, 'D2', 2);
INSERT INTO Departments (department_ID, department_Name, department_Chair) VALUES (3, 'D3', 3);
INSERT INTO Departments (department_ID, department_Name, department_Chair) VALUES (4, 'D4', 4);
INSERT INTO Departments (department_ID, department_Name, department_Chair) VALUES (5, 'D5', 5);


-- Query 1
SELECT enrollments.course_id, COUNT(students.student_id)
FROM students
    INNER JOIN enrollments ON enrollments.student_id=students.student_id
GROUP BY enrollments.course_id;

-- Query 2
SELECT enrollments.course_id, AVG(enrollments.enrollment_grade)
FROM students
    INNER JOIN enrollments ON enrollments.student_id=students.student_id
GROUP BY enrollments.course_id;

-- Query 3
SELECT students.*
FROM students WHERE NOT EXISTS (SELECT enrollments.student_id FROM enrollments WHERE enrollments.student_id=students.student_id);

-- Query 4
SELECT instructors.instructor_id
FROM instructors
    INNER JOIN departments ON departments.department_chair=instructors.instructor_id AND departments.department_name='Computer Science';

-- Query 5
SELECT students.student_id, AVG(enrollments.enrollment_grade)
FROM students
    INNER JOIN enrollments ON enrollments.student_id=students.student_id
GROUP BY students.student_id
