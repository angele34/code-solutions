USE dbsimple;

-- List all the student and the donations they gave (if applicable)
SELECT s.name, s.gradelevel, sd.fruitcode, sd.qty
FROM students s
LEFT JOIN studentdonations sd
ON s.name = sd.studentname
ORDER BY s.name;

-- List all the students, and the fruits donated to them (if they received fruits).
SELECT s.name, s.gradelevel, sf.fruitcode, sf.qty
FROM students s
LEFT JOIN studentfruit sf 
ON s.name = sf.studentname
ORDER BY s.name;

--  list all the fruits (regardless whether donated or not), 
-- the student-donors and the quantity the donor donated
SELECT f.fruitcode, f.description, f.qty AS FRUITQTY,
sd.studentname, sd.qty AS DONATIONQTY
FROM fruits f
LEFT JOIN studentdonations sd
ON f.fruitcode = sd.fruitcode
ORDER BY f.description;

-- add a record in studentfruit
-- INSERT INTO studentfruit 
-- VALUES('ANGELA', 'BANANA', 10);

-- List all the fruits, and the student that
-- received the fruit (if there is a student that received the fruit)
SELECT f.fruitcode, f.description, f.qty AS FRUITQTY,
sf.studentname, sf.fruitcode, sf.qty AS STUDENTFRUITQTY
FROM fruits f
LEFT JOIN studentfruit sf
ON f.fruitcode = sf.fruitcode
ORDER BY f.description;