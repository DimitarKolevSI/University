USE Hotel

--—ъединени€

--ƒа се изведат датите на освобождаване на фамилните стаи.
SELECT RS.checkOutDate FROM RESERVATIONS RS JOIN ROOMS R ON RS.roomNumber = R.roomNumber WHERE R.roomType LIKE 'Family';

--ƒа се изведат номерата на всички стаи, за които н€ма направена резерваци€.
SELECT DISTINCT R.roomNumber FROM ROOMS R LEFT JOIN RESERVATIONS RS ON RS.roomNumber = R.roomNumber WHERE RS.registerDate IS NULL

--ƒа се изведе средната цена по етаж, закръглена до два символа след запета€та, на стаите с единични легла. 
SELECT floor, FORMAT(AVG(RS.priceForNight),'N2') AS avgPrice FROM ROOMS R JOIN RESERVATIONS RS ON RS.roomNumber = R.roomNumber WHERE roomType LIKE 'Room' GROUP BY floor 

--ƒа се изведат имената на редовните клиенти и бро€т направени от т€х резервации през 2020г.(ƒа не се извеждат тези, които са без резервации)
SELECT firstName + ' ' + lastName as fullName, COUNT(C.clientsNumber) as NumberOfReservations FROM CLIENTS C JOIN RESERVATIONS R ON C.clientsNumber = r.clientsNumber
WHERE R.registerDate LIKE '2020%' GROUP BY firstName,lastName

--ƒа се изведе бро€т на резервации с включена закусна за клиентите настанени на трети€ етаж.
SELECT  COUNT(C.clientsNumber) AS clientsWithBreakfast FROM CLIENTS C JOIN RESERVATIONS R ON C.clientsNumber = r.clientsNumber JOIN ROOMS RM ON RM.roomNumber = R.roomNumber
WHERE RM.floor = 3 AND R.packet LIKE 'BB'
