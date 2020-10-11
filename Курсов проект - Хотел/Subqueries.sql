USE Hotel

--Подзявки

--Да се изведат ЕГН-тата на редовните клиенти направили резервация през 2020 година.
SELECT personalID FROM CLIENTS
WHERE clientsNumber IN ( SELECT clientsNumber FROM RESERVATIONS WHERE registerDate LIKE '2020%')

--Да се изведат номерата на стаите, в които са били настанени хора през месец Юли 2019 година.
SELECT roomNumber FROM ROOMS WHERE
roomNumber in (SELECT roomNumber FROM RESERVATIONS WHERE registerDate LIKE '2019-07%')

--Да се изведат адресите на всички редовни клиенти направили резервация.
SELECT address FROM CLIENTS WHERE
clientsNumber IN (SELECT clientsNumber FROM RESERVATIONS WHERE clientsNumber IS NOT NULL)

--Да се изведат видовете пакети на резервациите настанени в апартамент.
SELECT packet FROM RESERVATIONS WHERE
roomNumber IN (SELECT roomNumber FROM ROOMS WHERE roomType LIKE 'Apartment')

--Да се изведат без да се повтарят цената за нощувка на всички стаи от първия етаж.
SELECT DISTINCT priceForNight FROM RESERVATIONS WHERE
roomNumber IN (SELECT roomNumber FROM ROOMS WHERE floor LIKE 1)