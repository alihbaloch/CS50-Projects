-- Number of movies with an IMDb rating of 10.0

SELECT COUNT(rating) as imdb_10_rated FROM ratings WHERE rating = 10.0;