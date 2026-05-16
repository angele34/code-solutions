use dbsimple;

-- List all the student, and the donations (if applicable) they gave
SELECT s.name, s.gradelevel, sd.fruitcode, sd.qty
FROM students s
LEFT JOIN studentdonations sd
ON s.name = sd.studentname;

-- List all the students, and the fruits donated to them (if they received fruits).
SELECT s.name, s.gradelevel,
sf.fruitcode, sf.qty
FROM students s
LEFT JOIN studentfruit sf
ON sf.studentname = s.name;

-- INSERT INTO studentfruit VALUES ('ANGELA','BANANA', 10)

-- List all the fruits (regardless whether donated or not),
-- the student-donors and the quantity the donor donated.

SELECT f.fruitcode, f.description, f.qty AS FRUITQTY,
sd.studentname, sd.qty AS DONATIONQTY
FROM fruits f
LEFT JOIN studentdonations sd
ON sd.fruitcode = f.fruitcode
ORDER BY f.description;

-- List all the fruits, and the student
-- that received the fruit (if there is a student that received the fruit)
SELECT f.fruitcode, f.description, f.qty AS FRUITQTY,
sf.studentname, sf.qty AS STUDENTFRUITQTY
FROM fruits f
LEFT JOIN studentfruit sf
ON f.fruitcode = sf.fruitcode
ORDER BY f.description;

