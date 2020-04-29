USE Hotel

SELECT * FROM CLIENT WHERE address LIKE '%Sofia%';

SELECT clientsName FROM RESERVATIONS WHERE registerDate LIKE '2019-07%'

SELECT firstName,lastName,type,salary FROM EMPLOYEES WHERE salary < 1000;

SELECT firstName, lastName FROM EMPLOYEES WHERE workingHours > 8 AND salary >= 1000;

SELECT firstName, lastName FROM EMPLOYEES WHERE type LIKE 'piccolo' and gender LIKE 'F';

SELECT roomNumber FROM ROOM WHERE roomCapacity > 2 AND roomType LIKE 'Family' OR roomType LIKE 'Apartment'



SELECT firstName, lastName FROM EMPLOYEES WHERE personalID LIKE '8%'
UNION
SELECT firstName, lastName FROM CLIENT WHERE personalID LIKE '8%'

SELECT roomNumber FROM ROOM WHERE roomType LIKE 'Family'
EXCEPT
SELECT roomNumber FROM ROOM WHERE roomCapacity <= 2

SELECT roomNumber FROM RESERVATIONS WHERE registerDate LIKE '2019-07%'
EXCEPT
SELECT roomNumber FROM RESERVATIONS WHERE clientsNumber IS NULL

SELECT firstName, lastName FROM CLIENT WHERE address NOT LIKE '%Sofia'
INTERSECT
SELECT firstName, lastName FROM CLIENT WHERE gender LIKE 'F'

SELECT personalID FROM EMPLOYEES WHERE gender LIKE 'M'
INTERSECT
SELECT personalID FROM EMPLOYEES WHERE workingHours < 10