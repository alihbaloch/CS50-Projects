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

/*  According to Ruth: thief left from bakery parking lot by car after 10 min of theft (check bakery security footage from '10:15 - 10:25 am')
    According to Eugene: recognized theif -> theif withdrawed money from 'Leggett Street ATM'
    According to Raymond: Theif talked to someone for less than 1 minute



*/

SELECT transcript, name, day, month
FROM interviews
WHERE (
    day = 28 AND
    month = 7
);