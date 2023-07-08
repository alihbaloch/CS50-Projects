-- List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred

SELECT movies.title
FROM movies
    JOIN stars AS star_jd
    ON movies.id = star_jd.movie_id
    JOIN stars AS star_hbc
    ON movies.id = star_jd.movie_id
    JOIN people
    ON stars.person_id = people.id
WHERE people.name = 'Johnny Depp'



AND people.name = 'Helena Bonham Carter';