use employees;
-- CCINFOM
-- Module 2 Lesson 07: Queries involving Outer Joins
-- Estimated Time to consume material – 6.0 Hours
-- page
-- 5
-- EXERCISE:
-- Let us have an exercise on what we have learned from the lessons above. First, create a new database using the script file – dbemployees.sql.
-- Using the employees DB, write the SQL Statement that will satisfy each data requirement below. This is a BIG script, so do not be surprised if it takes time to
-- be imported using MYSQL Workbench to create the DB, as well as when you execute your scripts. Collect your SQL Statements in an SQL Script file and
-- name the file using your Lastname_Firstname – SQL Lesson 07.sql. You may upload your output in the corresponding practice exercise link posted in
-- AnimoSpace. Answers to the practice exercise will also be posted.


-- 1. List all the employees, and the department currently being or 
-- previously managed and the date of assignment as manager (if they manage a department). 
-- Sort the list by the date of assignment as manager (latest assignment first).

SELECT s.emp_number, CONCAT(s.last_names, ' ', s.first_names) AS complete_name,
d.dept_name, dm.emp_no, dm.from_date
FROM staff s
LEFT JOIN dept_manager dm
ON dm.emp_no = s.emp_number
LEFT JOIN departments d
ON d.dept_no = dm.dept_no
ORDER BY dm.from_date DESC;

-- 2. List all the employees (employee number and complete name), and the titles
--  they were assigned (if they were assigned titles). Sort the list such that employees
-- without titles appear first and should they have titles, sort if by employee name).

SELECT s.emp_number, CONCAT(s.last_names, ' ', s.first_names) AS complete_name, t.title
FROM staff s
LEFT JOIN titles t
ON s.emp_number = t.emp_no
ORDER BY
t.title, 
complete_name;

-- 3. List all the departments (department name), 
-- and all the current and previous managers (employee number and date of assignment).
-- Sort the list by department name and latest assignment first.

SELECT d.dept_name, dm.emp_no, dm.from_date
FROM departments d
JOIN dept_manager dm
ON d.dept_no = dm.dept_no
ORDER BY d.dept_name, dm.from_date DESC;