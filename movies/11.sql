-- List the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated

SELECT movies.title, stars.movie, ratings.movie_id
FROM movies
    JOIN stars
    ON movies.id = stars.movie_id
WHERE stars.person_id = 'Chadwick Boseman"




