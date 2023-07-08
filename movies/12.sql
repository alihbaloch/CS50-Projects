-- List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred

SELECT movies.title
FROM movies
    JOIN stars AS s_jd
    ON movies.id = s_jd.movie_id
    JOIN stars AS s_hbc
    ON movies.id = s_hbc.movie_id
    JOIN people AS p_jd
    ON s_jd.person_id = people.id
    JOIN people AS p_hbc
    ON s_hbc.movie_id = people.id
WHERE people.name = 'Johnny Depp'



AND people.name = 'Helena Bonham Carter';