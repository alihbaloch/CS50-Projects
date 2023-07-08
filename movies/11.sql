-- List the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated

SELECT movies.title
FROM movies
    JOIN stars
    ON movies.id = stars.movie_id
    -- FROM stars
        JOIN people
    JOIN people
    ON stars.person_id = people.id
    JOIN ratings
    ON stars.movie_id = ratings.movie_id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating ASC
LIMIT 5;








