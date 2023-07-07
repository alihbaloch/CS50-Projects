--  Names of all people who starred in a movie released in 2004, ordered by birth year

SELECT name
FROM people
    WHERE id IN (SELECT person_id FROM stars
    WHERE movie_id IN (SELECT id FROM movies
    WHERE year = 2004))
    ORDER BY birth;



 -- CHECK THIS AGAIN, DISTINCT USE OR NOT? BOTH SEEM CORRECT. ALSO CHECK THE FORMAT/STYLE OF ALL SQL QUERIES IN THIS DATABASE, REFER TO THE SQL STYLE GUIDE!