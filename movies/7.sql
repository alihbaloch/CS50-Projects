-- All movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.

SELECT movies.title, ratings.rating
    WHERE movies.year = 2018
    FROM movies
    JOIN ratings ON movies.id = ratings.movie_id;