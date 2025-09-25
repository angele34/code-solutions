use dbsimple;

-- 1.
SELECT * FROM students, studentfruit;

-- 2.
SELECT *
FROM students
JOIN studentfruit
ON students.name = studentfruit.studentname;

-- 3.
SELECT *
FROM students
LEFT JOIN studentfruit
ON students.name = studentfruit.studentname

-- 4.
SELECT *
FROM studentfruit
UNION
SELECT *
FROM studentdonations;

-- 5.
SELECT name, gradelevel,
NULL as qty
FROM students
UNION
SELECT *
FROM studentfruit;