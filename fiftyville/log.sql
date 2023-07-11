-- Keep a log of any SQL queries you execute as you solve the mystery.


SELECT street, day, month, description
FROM crime_scene_reports
WHERE (
    street = 'Humphrey Street' AND
    day = 28 AND
    month = 7
);


SELECT transcript, name, day, month
FROM interviews
WHERE (
    day = 28 AND
    month = 7
);

/*
    Theft of duck took place at '10:15am'
    3 witnesses interviewed who were present at the time
    All of them mention the 'Bakery'
    littering at 16:36 / probably irrelevant

    According to Ruth: thief left from bakery parking lot by car after 10 min of theft (check bakery security footage from '10:15 - 10:25 am')
    According to Eugene: recognized thief -> thief withdrawed money from 'Leggett Street ATM'
    According to Raymond: Thief talked to someone for 'LESS THAN 1 MINUTE'. Thief 'PLANNED TO LEAVE BY EARLIEST FLIGHT TOMORROW -> ON JULY 29'
                          person on the phone possibly bought the flight ticket
*/


-- All individuals who left bakery parking lot between 10:15 - 10:25 am and withdrawed money from Leggett Street ATM on the day and month of the robbery


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


-- All phone calls made with a duration of less than 60 seconds, on the day and month of the robbery

SELECT caller, receiver
FROM phone_calls
WHERE phone_calls.duration < 60
    AND phone_calls.day = 28
    AND phone_calls.month = 7;

 /* Based on the phone calls made in the time-period of the robbery, with durations of less than 60 seconds,
    2 numbers match from the info we already gathered from bakery and atm.
    2 people of interest:
    Bruce (passport no: 5773159633) -> called (375) 555-8161 (potential accomplice)
    Diana (passport no: 3592750733) -> called (725) 555-3243 (potential accomplice)
*/


-- CHECK if POI passports in earliest flights the next morning on July 29


SELECT passengers.passport_number, flights.hour, flights.minute
FROM passengers
    JOIN flights ON flights.id = passengers.flight_id
    JOIN airports ON flights.origin_airport_id = airports.id
WHERE airports.city = 'Fiftyville'
    AND flights.day = 29
    AND flights.month = 7
    AND flights.year = 2021
ORDER BY flights.hour ASC;

/* Passport number for Bruce found.
   He left from the earliest flight tomorrow morning at 8:20
*/

-- Check for destination city to see what city Bruce escaped to

SELECT city FROM airports
WHERE airports.id IN (
    SELECT destination_airport_id
    FROM flights
    WHERE flights.id IN (
        SELECT flight_id
        FROM Passengers
        WHERE passengers.passport_number = 5773159633
    )
);

-- Bruce escaped to NEW YORK CITY

-- Check for name of accomplice, check by phone_number Bruce called - (375) 555-8161

SELECT name
FROM people
WHERE people.phone_number = '(375) 555-8161';

-- The number points to someone named ROBIN - ROBIN is Bruce's Accomplice

/* Based on all this information, Bruce was the only person who 