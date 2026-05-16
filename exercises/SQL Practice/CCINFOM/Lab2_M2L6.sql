USE employees;
-- 1. List all the employees, 
-- and the department currently being or previously managed 
-- and the date of assignment as manager (if they manage a department). 
-- Sort the list by the date of assignment as manager (latest assignment first)
SELECT s.emp_number, s.first_names, s.last_names,
d.dept_name, dm.from_date
FROM staff s
LEFT JOIN dept_manager dm
ON s.emp_number = dm.emp_no
LEFT JOIN departments d
ON d.dept_no =  dm.dept_no
ORDER BY
dm.from_date DESC;
-- 2. List all the employees (employee number and complete name), 
-- and the titles they were assigned (if they were assigned titles). Sort the
-- list such that employees without titles appear first and 
-- should they have titles, sort if by employee name)
SELECT s.emp_number, s.first_names, s.last_names, t.title
FROM staff s
LEFT JOIN titles t
ON s.emp_number = t.emp_no
ORDER BY 
	t.title IS NOT NULL,
    s.first_names,
    s.last_names;
-- List all the departments (department name), 
-- and all the current and previous managers (employee number and date of assignment). Sort
-- the list by department name and latest assignment first.
SELECT d.dept_name, dm.emp_no, dm.from_date
FROM departments d
JOIN dept_manager dm
ON d.dept_no = dm.dept_no
ORDER BY 
	d.dept_name ASC,
    dm.from_date DESC;
    
 
