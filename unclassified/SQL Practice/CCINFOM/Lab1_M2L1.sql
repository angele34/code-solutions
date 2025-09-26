
-- 1. Get all the cities of Thailand
SELECT Name
FROM city
WHERE CountryCode = (
	SELECT code
    FROM country
    WHERE Name = 'Thailand');
    
-- 2. Get all the cities of Thailand with a population of more than 100,000
SELECT *
FROM city
WHERE CountryCode = (
	SELECT code
    FROM country
    WHERE Name = 'Thailand')
AND population > 100000;

-- 3. Get all the countries with a life expectancy of 70 to 80 years old
SELECT *
FROM country
WHERE LifeExpectancy BETWEEN 70 AND 80;

-- 4. Get all the continents with countries having a population below 1,000
SELECT DISTINCT Continent
FROM country
WHERE Population < 1000;

-- 5. Get all the countries (name, continent, governmentform) that are Republics
SELECT Name, Continent, GovernmentForm
FROM country
WHERE GovernmentForm = 'Republic';

-- 6. Get all the countries that has celebrated at least 100 years of independence
-- Following the year the module was created (2021)
SELECT Name, IndepYear, (2021-IndepYear) AS YearsIndependent
FROM country
WHERE (2021 - IndepYear) >= 100;

-- 7. Get all the districts of Bangladesh
SELECT DISTINCT District
FROM city
WHERE CountryCode = (
	SELECT Code
    FROM country
    WHERE Name = 'Bangladesh'
);

-- 8. Get all the countries where more than 80% speaks Arabic
SELECT c.Name, cl.Language, cl.Percentage
FROM country c
JOIN countrylanguage cl ON c.Code = cl.CountryCode
WHERE cl.Language = 'Arabic' 
AND cl.Percentage >= 80;