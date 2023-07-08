-- List the names of all people who starred in a movie in which Kevin Bacon also starred

SELECT people.name
FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN movies ON stars.movie_id = movies.id;
    JOIN stars AS kb ON movies.id = kb.movie_id
    JOIN people AS person_kb ON kb.person_id = person_kb.id
WHERE person_kb.name = 'Kevin Bacon' AND person_kb.birth = 1958 AND people.name <> 'Kevin Bacon';