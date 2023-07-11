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
    According to Eugene: recognized thief -> thief withdrawed money from 'Leggett Street ATM'
    According to Raymond: Thief talked to someone for 'LESS THAN 1 MINUTE'. Thief 'PLANNED TO LEAVE BY EARLIEST FLIGHT TOMORROW -> ON JULY 29'
                          person on the phone possibly bought the flight ticket

                          TRY JOINING BAKERY + ATM_TRANSACTIONS + BANK_ACCOUNTS + PEOPLE + FLIGHTS
*/

SELECT transcript, name, day, month
FROM interviews
WHERE (
    day = 28 AND
    month = 7
);


/* All individuals who left bakery parking lot between 10:15 - 10:25 am and withdrawed money from Leggett Street ATM on the day and month of the robbery */


SELECT people.id, people.name, people.phone_number, people.passport_number, people.license_plate, bakery_security_logs.activity, bakery_security_logs.hour, bakery_security_logs.minute
FROM people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
    JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE atm_transactions.day = 28
    AND atm_transactions.month = 7
    AND atm_transactions.atm_location = 'Leggett Street'
    AND atm_transactions.transaction_type = 'withdraw'
    AND bakery_security_logs.hour = 10
    AND bakery_security_logs.minute BETWEEN 15 AND 25;



SELECT id, caller, receiver
FROM phone_calls
WHERE phone_calls.duration < 60
    AND phone_calls.month = 7
    AND phone_calls.day = 28;


SELECT airports.id, airports.full_name, flights.orgin_airport_id, flights.destination_airport_id
FROM airports
    JOIN flights ON airports.id = flights.id
    JOIN passengers ON flights.id = passengers.flight_id
WHERE or =