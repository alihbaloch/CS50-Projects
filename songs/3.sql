-- Top 5 longest songs - in DESC order of length

SELECT name FROM songs
    ORDER by duration_ms DESC
    LIMIT 5;