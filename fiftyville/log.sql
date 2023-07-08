-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports;

SELECT street, day, month, description
FROM crime_scene_reports
WHERE (
    street = 'Humphrey Street' AND
    day = 28 AND
    month = 7
);