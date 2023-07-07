-- All movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.

SELECT movies.title WHERE year = 2018, ratings.rating
    FROM movies JOIN ratings ON 