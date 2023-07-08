-- Titles and release years of all Harry Potter movies, in chronological order

SELECT COUNT(title), year
FROM movies
WHERE title LIKE 'Harry Potter%'
ORDER BY year ASC;