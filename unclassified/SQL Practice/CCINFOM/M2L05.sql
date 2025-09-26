USE dbworld;

-- Generate the list of countries 
-- (country name and continent) that uses English as the official language

SELECT c.Name, c.Continent
FROM country c
JOIN countrylanguage cl
ON c.Code = cl.CountryCode
WHERE cl.Language = 'English'
AND cl.IsOfficial = 'T';

-- Generate the list of official languages used by countries in Africa
SELECT c.Name, cl.Language
FROM countrylanguage cl
JOIN country c
ON cl.CountryCode = c.code
WHERE c.Continent = 'Africa'
AND cl.IsOfficial = 'T';

-- Generate the list of cities (city name and country name)
-- in North America with a population of more than 1 million
SELECT ci.Name AS 'City Name', c.Name AS 'Country Name'
FROM city ci
JOIN country c
ON ci.CountryCode = c.Code
WHERE c.Continent = 'North America'
AND ci.Population > 1000000;

-- Can you think of a requirement that will join all the tables in this database? 
-- Write the requirement and its corresponding SQL Statement

-- Generate the list of cities, their population, and corresponding country names
-- located in Asia where the city population is at least 30,000
-- and the official language is Chinese


SELECT ci.Name AS 'City Name', ci.Population,
c.Name AS 'Country Name'
FROM city ci
JOIN country c
ON c.Code = ci.CountryCode
JOIN countryLanguage cl
ON ci.CountryCode = cl.CountryCode
WHERE ci.Population >= 30000
AND cl.Language = 'Chinese'
AND cl.IsOfficial = 'T'
ORDER BY c.Name DESC;

