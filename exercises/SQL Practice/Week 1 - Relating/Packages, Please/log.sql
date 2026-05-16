
-- *** The Lost Letter ***

-- At what type of address did the Lost Letter end up?:
SELECT "type" FROM "addresses" WHERE id = (
    SELECT "address_id" FROM "scans" WHERE "package_id" = (
        SELECT "id" FROM "packages"
        WHERE "from_address_id" = (
            SELECT "id" FROM "addresses" WHERE "address" = '900 Somerville Avenue'
        )
        AND
        "to_address_id" = (
            SELECT "id" FROM "addresses" WHERE "address" = '2 Finnigan Street'
        )
    )
    AND "action" = 'Drop'
);

-- At what address did the Lost Letter end up?:
SELECT "address" FROM "addresses" WHERE id = (
    SELECT "address_id" FROM "scans" WHERE "package_id" = (
        SELECT "id" FROM "packages"
        WHERE "from_address_id" = (
            SELECT "id" FROM "addresses" WHERE "address" = '900 Somerville Avenue'
        )
        AND
        "to_address_id" = (
            SELECT "id" FROM "addresses" WHERE "address" = '2 Finnigan Street'
        )
    )
    AND "action" = 'Drop'
);

-- *** The Devious Delivery ***
-- At what type of address did the Devious Delivery end up?:
SELECT * FROM "packages" WHERE "from_address_id" IS NULL;
+------+---------------+-----------------+---------------+
|  id  |   contents    | from_address_id | to_address_id |
+------+---------------+-----------------+---------------+
| 5098 | Duck debugger | NULL            | 50            |
+------+---------------+-----------------+---------------+

SELECT "type" FROM "addresses" WHERE id = (
    SELECT "address_id" FROM "scans" WHERE "package_id" = (
        SELECT "id" FROM "packages" WHERE "from_address_id" IS NULL
    )
    AND
    "action" = 'Drop'
);

--What were the contents of the Devious Delivery?
SELECT "contents" FROM "packages" WHERE "from_address_id" IS NULL;

-- *** The Forgotten Gift ***
-- What are the contents of the Forgotten Gift?
SELECT * FROM "packages" WHERE "from_address_id" = (
    SELECT "id" FROM "addresses" WHERE "address" = '109 Tileston Street'
);

+------+----------+-----------------+---------------+
|  id  | contents | from_address_id | to_address_id |
+------+----------+-----------------+---------------+
| 9523 | Flowers  | 9873            | 4983          |
+------+----------+-----------------+---------------+

-- granddaughter's place
SELECT * FROM "addresses" WHERE "address" = '728 Maple Place';
+------+-----------------+-------------+
|  id  |     address     |    type     |
+------+-----------------+-------------+
| 4983 | 728 Maple Place | Residential |
+------+-----------------+-------------+

--Who has the Forgotten Gift?:
SELECT "address" FROM "addresses" WHERE "id" = (
    SELECT "address_id" FROM "scans" WHERE "package_id" IN (
        SELECT "id" FROM "packages" WHERE "from_address_id" = (
            SELECT "id" FROM "addresses" WHERE "address" = '109 Tileston Street'
        )
        AND "action" = 'Pick'
    )
);

SELECT * FROM "scans" WHERE "package_id" IN (
    SELECT "id" FROM "packages" WHERE "from_address_id" = (
        SELECT "id" FROM "addresses" WHERE "address" = '109 Tileston Street'
    )
);
