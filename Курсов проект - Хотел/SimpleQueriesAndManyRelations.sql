USE Hotel

--������ ������

--�� �� ������� ������� � ������� ������ ������� �������, ������� � �����. 
SELECT firstName + ' ' + lastName as fullName, address FROM CLIENTS WHERE address LIKE '%Sofia';

--�� �� ������� ������� �� ������ ������� ��������� ���������� �� ����� ��� 2019 ������
SELECT clientsName FROM RESERVATIONS WHERE registerDate LIKE '2019-07%'

--�� �� ������� �������, ���������� � ��������� �� ������ ��������� ��� ������� ��� 1000 ��.
SELECT firstName + ' ' + lastName as fullName,type,salary FROM EMPLOYEES WHERE salary < 1000;

--�� �� ������� ������� �� ������ ��������� �������� ��� 8 ���� � ������� 1000 ��� ������ ����.
SELECT firstName + ' ' + lastName as fullName FROM EMPLOYEES WHERE workingHours > 8 AND salary >= 1000;

--�� �� ������� ������� �� ������ ���� ��������� � �������� ������.
SELECT firstName + ' ' + lastName as fullName FROM EMPLOYEES WHERE type LIKE 'piccolo' and gender LIKE 'F';

--�� �� ������� �������� �� ������ ������� ���� ��� ����������� � ��������� ��� ����� ����. 
SELECT roomNumber FROM ROOMS WHERE roomCapacity > 2 AND roomType LIKE 'Family' OR roomType LIKE 'Apartment'


--������ ����� ��� ��� ������ �������

--�� �� ������� ������� �� ������ ��������� � ������� ������� ������ ���� 80-��.
SELECT firstName + ' ' + lastName as fullName FROM EMPLOYEES WHERE personalID LIKE '8%'
UNION
SELECT firstName + ' ' + lastName as fullName FROM CLIENTS WHERE personalID LIKE '8%'

--�� �� ������� �������� �� ������ ������� ����, ����� �� � ��������� ����� ��� ��-����� ����.
SELECT roomNumber FROM ROOMS WHERE roomType LIKE 'Family'
EXCEPT
SELECT roomNumber FROM ROOMS WHERE roomCapacity <= 2

--�� �� ������� �������� �� ������ ���� ����������� ���� ��� 2019 � ���������� �� ���� ��������� �� �� ������� �������.
SELECT roomNumber FROM RESERVATIONS WHERE registerDate LIKE '2019-07%'
EXCEPT
SELECT roomNumber FROM RESERVATIONS WHERE clientsNumber IS NULL

--�� �� ������� ������� �� ������ ������� �������, �� ������ � ����� � �� ����.
SELECT firstName + ' ' + lastName as fullName FROM CLIENTS WHERE address NOT LIKE '%Sofia'
INTERSECT
SELECT firstName + ' ' + lastName as fullName FROM CLIENTS WHERE gender LIKE 'F'

--�� �� ������� ���-���� �� ������ ��������� ���� � �� ������ ��������� �������� ��� 10 ����
SELECT personalID FROM EMPLOYEES WHERE gender LIKE 'M'
INTERSECT
SELECT personalID FROM EMPLOYEES WHERE workingHours < 10