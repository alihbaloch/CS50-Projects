-- Names of all people who have directed a movie that received a rating of at least 9.0

SELECT name
    FROM people
    WHERE id IN (SELECT person_id FROM directors)