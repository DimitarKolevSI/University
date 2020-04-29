USE Hotel

SELECT RS.checkOutDate FROM RESERVATIONS RS JOIN ROOM R ON RS.roomNumber = R.roomNumber WHERE R.roomType LIKE 'Family';

SELECT DISTINCT R.roomNumber FROM ROOM R LEFT JOIN RESERVATIONS RS ON RS.roomNumber = R.roomNumber WHERE RS.registerDate IS NULL

SELECT floor, AVG(RS.priceForNight) AS avgPrice FROM ROOM R JOIN RESERVATIONS RS ON RS.roomNumber = R.roomNumber WHERE roomType LIKE 'Room' GROUP BY floor 

SELECT firstName, lastName, COUNT(C.clientsNumber) as NumberOfReservations FROM CLIENT C JOIN RESERVATIONS R ON C.clientsNumber = r.clientsNumber
WHERE R.registerDate LIKE '2020%' GROUP BY firstName,lastName

SELECT  COUNT(C.clientsNumber) AS clientsWithBreakfast FROM CLIENT C JOIN RESERVATIONS R ON C.clientsNumber = r.clientsNumber JOIN ROOM RM ON RM.roomNumber = R.roomNumber
WHERE RM.floor = 3 AND R.packet LIKE 'Breakfast'
