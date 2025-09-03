-- Compiled SQL Queries for the Cyberchase Problem Set 0

1. SELECT "title" FROM "episodes" WHERE "season" = 1;
2. SELECT "season", "title"  FROM "episodes" WHERE "episode_in_season" = 1;
3. SELECT "production_code" FROM "episodes" WHERE "title" = 'Hackerized!';
4. SELECT "title" FROM "episodes" WHERE "topic" IS NULL;
5. SELECT "title" FROM "episodes" WHERE "air_date" = '2004-12-31';
6. SELECT "title"  FROM "episodes" WHERE "season" = 6 AND  "air_date" LIKE '%2007%';
7. SELECT "title", "topic" FROM "episodes"  WHERE "topic" LIKE '%fractions%';
8. SELECT COUNT("title") FROM "episodes" WHERE "air_date" BETWEEN '2018-01-01' AND '2023-12-31';
9. SELECT COUNT("title") FROM "episodes" WHERE "air_date" BETWEEN '2002-01-01' AND '2007-12-31';
10. SELECT "id", "title", "production_code" FROM "episodes" ORDER BY "production_code" ASC;
11. SELECT "title" FROM "episodes" WHERE "season" = 5
    ORDER BY "title" DESC;
12. SELECT COUNT(DISTINCT("title")) FROM "episodes";
13. SELECT "title" FROM "episodes" WHERE "title" LIKE "The%"
