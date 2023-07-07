--  Names of all people who starred in a movie released in 2004, ordered by birth year

SELECT name FROM people
    WHERE id IN (SELECT person_id IN stars WHERE movie_id)