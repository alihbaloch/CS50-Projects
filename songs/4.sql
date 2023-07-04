-- names of any songs that have danceability, energy, and valence greater than 0.75

SELECT name FROM songs
    WHERE danceability AND Energy AND valence > 0.75;