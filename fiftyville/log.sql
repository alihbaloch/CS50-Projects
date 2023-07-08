-- Keep a log of any SQL queries you execute as you solve the mystery.

/* Theft of duck took place at '10:15am'
3 witnesses interviewed who were present at the time
All of them mention the 'Bakery'
littering at 16:36 / probably irrelevant  */

SELECT street, day, month, description
FROM crime_scene_reports
WHERE (
    street = 'Humphrey Street' AND
    day = 28 AND
    month = 7
);

SELECT id, transcript, name, day, month
FROM interviews
WHERE (
    day = 28 AND
    month = 7
);