-- Number of movies with an IMDb rating of 10.0

WRONG!

SELECT COUNT(id) AS imdb_10_rated
FROM movies IN (
    SELECT movie_id FROM ratings
    WHERE rating = 10.0
);