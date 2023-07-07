-- All movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.

SELECT title FROM movies WHERE year = 2018 IN (SELECT ratings FROM rating) ORDER BY (SELECT rating FROM ratings) DESC;