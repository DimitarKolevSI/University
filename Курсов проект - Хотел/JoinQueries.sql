USE Hotel

--����������

--�� �� ������� ������ �� ������������� �� ��������� ����.
SELECT RS.checkOutDate FROM RESERVATIONS RS JOIN ROOMS R ON RS.roomNumber = R.roomNumber WHERE R.roomType LIKE 'Family';

--�� �� ������� �������� �� ������ ����, �� ����� ���� ��������� ����������.
SELECT DISTINCT R.roomNumber FROM ROOMS R LEFT JOIN RESERVATIONS RS ON RS.roomNumber = R.roomNumber WHERE RS.registerDate IS NULL

--�� �� ������ �������� ���� �� ����, ���������� �� ��� ������� ���� ���������, �� ������ � �������� �����. 
SELECT floor, FORMAT(AVG(RS.priceForNight),'N2') AS avgPrice FROM ROOMS R JOIN RESERVATIONS RS ON RS.roomNumber = R.roomNumber WHERE roomType LIKE 'Room' GROUP BY floor 

--�� �� ������� ������� �� ��������� ������� � ����� ��������� �� ��� ���������� ���� 2020�.(�� �� �� �������� ����, ����� �� ��� ����������)
SELECT firstName + ' ' + lastName as fullName, COUNT(C.clientsNumber) as NumberOfReservations FROM CLIENTS C JOIN RESERVATIONS R ON C.clientsNumber = r.clientsNumber
WHERE R.registerDate LIKE '2020%' GROUP BY firstName,lastName

--�� �� ������ ����� �� ���������� � �������� ������� �� ��������� ��������� �� ������ ����.
SELECT  COUNT(C.clientsNumber) AS clientsWithBreakfast FROM CLIENTS C JOIN RESERVATIONS R ON C.clientsNumber = r.clientsNumber JOIN ROOMS RM ON RM.roomNumber = R.roomNumber
WHERE RM.floor = 3 AND R.packet LIKE 'BB'
