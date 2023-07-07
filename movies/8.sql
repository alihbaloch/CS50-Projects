-- Names of all people who starred in Toy Story

SELECT name AS Stars_in_Toy_Story FROM people
    WHERE id IN (SELECT person_id FROM stars
    WHERE movie_id IN (SELECT id FROM movies
    WHERE title = 'Toy Story'));


SELECT people.name
    FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN movies ON stars.movie_id = movies.id
    WHERE movies.title = 'Toy Story';