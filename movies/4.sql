-- Number of movies with an IMDb rating of 10.0

WRONG!

SELECT COUNT(rating) AS imdb_10_rated
FROM ratings
WHERE rating = 10.0;