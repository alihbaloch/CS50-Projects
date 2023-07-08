-- Number of movies with an IMDb rating of 10.0

WRONG!

SELECT COUNT(id) AS imdb_10_rated
FROM movies
WHERE id IN (
    SELECT movie_id FROM ratings
    WHERE rating = 10.0
);