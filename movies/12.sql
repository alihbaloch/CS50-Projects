-- List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred

SELECT movies.title
FROM movies
    JOIN stars AS s1
    ON movies.id = s1.movie_id
    JOIN stars AS s2
    ON movies.id = s2.movie_id
    JOIN people AS p1
    ON s_jd.person_id = p_jd.id
    JOIN people AS p2
    ON s_hbc.movie_id = p_hbc.id
WHERE people.name = 'Johnny Depp'



AND people.name = 'Helena Bonham Carter';