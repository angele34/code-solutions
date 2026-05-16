-- Compiled SQL Queries for the Players Problem Set 0

1. SELECT "birth_city", "birth_state", "birth_country"
   FROM "players"
   WHERE "first_name" = 'Jackie' AND
   "last_name" = 'Robinson';
2. SELECT "bats"
   FROM "players"
   WHERE "first_name" = 'Babe'
   AND "last_name" = 'Ruth';
3. SELECT "id"
   FROM "players"
   WHERE "debut" IS NULL;
4. SELECT "first_name", "last_name"
   FROM "players"
   WHERE "birth_country" != 'USA'
   ORDER BY "first_name", "last_name";
5. SELECT "first_name", "last_name"
   FROM "players"
   WHERE "bats" = 'R'
   ORDER BY "first_name", "last_name";
6. SELECT "first_name", "last_name", "debut"
   FROM "players"
   WHERE "birth_city" = 'Pittsburgh' AND
   "birth_state" = 'PA'
   ORDER BY "debut" DESC, "first_name", "last_name";
7. SELECT COUNT(DISTINCT("id"))
   FROM "players"
   WHERE ("bats" = 'R' AND "throws" = 'L')
   OR ("bats" = 'L' AND "throws" = 'R');
8. SELECT ROUND(AVG("height"), 2) AS "Average Height",
   ROUND(AVG("weight"), 2) AS "Average Weight"
   FROM "players"
   WHERE "debut" >= '2000-01-01';
9. SELECT "first_name", "last_name"
   FROM "players"
   WHERE "final_game" LIKE '%2022%'
   ORDER BY "first_name", "last_name";
10. SELECT "id" AS 'ID of Players with Right throws'
    FROM "players"
    WHERE "throws" = 'R'
    ORDER BY "id";











