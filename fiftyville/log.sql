-- Keep a log of any SQL queries you execute as you solve the mystery.

/*  Theft of duck took place at '10:15am'
    3 witnesses interviewed who were present at the time
    All of them mention the 'Bakery'
    littering at 16:36 / probably irrelevant
*/

SELECT street, day, month, description
FROM crime_scene_reports
WHERE (
    street = 'Humphrey Street' AND
    day = 28 AND
    month = 7
);

/*  According to Ruth: thief left from bakery parking lot by car after 10 min of theft (check bakery security footage from '10:15 - 10:25 am')
    According to Eugene: recognized theif -> theif withdrawed money from 'Leggett Street ATM'
    According to Raymond: Theif talked to someone for 'LESS THAN 1 MINUTE'. Theif 'PLANNED TO LEAVE BY EARLIEST FLIGHT TOMORROW -> ON JULY 29'
                          person on the phone possibly bought the flight ticket
*/

SELECT transcript, name, day, month
FROM interviews
WHERE (
    day = 28 AND
    month = 7
);

/*SELECT month, day, atm_location, transaction_type, amount, account_number
FROM atm_transactions
WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND account_number IN (SELECT account_number FROM bank_accounts);
*/

SELECT id, license_plate, activity, month, day, hour, minute
FROM bakery_security_logs
WHERE id = (SELECT id FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 1);