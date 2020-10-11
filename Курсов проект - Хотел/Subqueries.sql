USE Hotel

--��������

--�� �� ������� ���-���� �� ��������� ������� ��������� ���������� ���� 2020 ������.
SELECT personalID FROM CLIENTS
WHERE clientsNumber IN ( SELECT clientsNumber FROM RESERVATIONS WHERE registerDate LIKE '2020%')

--�� �� ������� �������� �� ������, � ����� �� ���� ��������� ���� ���� ����� ��� 2019 ������.
SELECT roomNumber FROM ROOMS WHERE
roomNumber in (SELECT roomNumber FROM RESERVATIONS WHERE registerDate LIKE '2019-07%')

--�� �� ������� �������� �� ������ ������� ������� ��������� ����������.
SELECT address FROM CLIENTS WHERE
clientsNumber IN (SELECT clientsNumber FROM RESERVATIONS WHERE clientsNumber IS NOT NULL)

--�� �� ������� �������� ������ �� ������������ ��������� � ����������.
SELECT packet FROM RESERVATIONS WHERE
roomNumber IN (SELECT roomNumber FROM ROOMS WHERE roomType LIKE 'Apartment')

--�� �� ������� ��� �� �� �������� ������ �� ������� �� ������ ���� �� ������ ����.
SELECT DISTINCT priceForNight FROM RESERVATIONS WHERE
roomNumber IN (SELECT roomNumber FROM ROOMS WHERE floor LIKE 1)