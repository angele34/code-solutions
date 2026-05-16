-- Compiled SQL Queries for the 36 Views Problem Set 0

1. SELECT "japanese_title", "english_title" FROM "views";
2. SELECT "average_color" FROM "views"
   WHERE "english_title" LIKE '%river%'
   AND "artist" = 'Hokusai';
3. SELECT COUNT("average_color") FROM "views"
   WHERE "english_title" LIKE '%Fuji%' AND "artist" = 'Hokusai';
4. SELECT COUNT("english_title") FROM "views"
   WHERE "artist" = 'Hiroshige' AND
   "english_title" LIKE '%Eastern%Capital%';
5. SELECT MAX("contrast") AS "Maximum Contrast"
   FROM "views"
   WHERE "artist" = 'Hokusai';
6. SELECT ROUND(AVG("entropy"), 2) AS "Hiroshige Average Entropy"
   FROM "views"
   WHERE "artist" = 'Hiroshige';
7. SELECT "english_title"
   FROM "views"
   WHERE "artist" = 'Hiroshige'
   ORDER BY "brightness" DESC
   LIMIT 5;
8. SELECT "english_title" FROM "views"
   WHERE "artist" = 'Hokusai'
   ORDER BY "contrast" ASC
   LIMIT 5;
9. SELECT "english_title", "artist"
   FROM "views"
   WHERE "brightness" = (SELECT(MAX("brightness")) FROM "views");
10. SELECT "english_title", "entropy"
    AS "Max Entropy"
    FROM "views"
    WHERE "artist" = 'Hokusai'
    ORDER BY "entropy" ASC
    LIMIT 3;





