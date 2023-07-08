-- Names of all people who starred in Toy Story

SELECT name AS stars_in_toy_story
FROM people
WHERE id IN (
    SELECT person_id
    FROM stars
    WHERE movie_id IN (
        SELECT id
        FROM movies
        WHERE title = 'Toy Story'
    )
);

