-- List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred

SELECT movies.title
FROM movies
    JOIN people ON movie.id = people.id
WHERE people.name = " "Johnny Depp", "Helena Bonham Carter" ";