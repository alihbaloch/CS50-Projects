-- List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred

SELECT movies.title
FROM movies
    JOIN stars AS jd
    ON movies.id = jd.movie_id
    JOIN stars AS hc
    ON movies.id = hc.movie_id
    JOIN people AS p_jd
    ON jd.person_id = p_jd.id
    JOIN people AS p_hc
    ON hc.person_id = p_hc.id
WHERE p_jd.name = 'Johnny Depp' AND p_hc.name = 'Helena Bonham Carter';