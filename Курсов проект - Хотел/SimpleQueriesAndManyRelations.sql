USE Hotel

--Прости заявки

--Да се изведат имената и адресът всички редовни клиенти, живеещи в София. 
SELECT firstName + ' ' + lastName as fullName, address FROM CLIENTS WHERE address LIKE '%Sofia';

--Да се изведат имената на всички клиенти направили резервация за месец Юли 2019 година
SELECT clientsName FROM RESERVATIONS WHERE registerDate LIKE '2019-07%'

--Да се изведат имената, длъжността и заплатата на всички служители със заплата под 1000 лв.
SELECT firstName + ' ' + lastName as fullName,type,salary FROM EMPLOYEES WHERE salary < 1000;

--Да се изведат имената на всички служители работещи над 8 часа и заплата 1000 или повече лева.
SELECT firstName + ' ' + lastName as fullName FROM EMPLOYEES WHERE workingHours > 8 AND salary >= 1000;

--Да се изведат имената на всички жени служители с длъжност пиколо.
SELECT firstName + ' ' + lastName as fullName FROM EMPLOYEES WHERE type LIKE 'piccolo' and gender LIKE 'F';

--Да се изведат номерата на всички фамилни стаи или апартаменти с капацитет над двама души. 
SELECT roomNumber FROM ROOMS WHERE roomCapacity > 2 AND roomType LIKE 'Family' OR roomType LIKE 'Apartment'


--Заявки върху две или повече релации

--Да се изведат имената на всички служители и редовни клиенти родени през 80-те.
SELECT firstName + ' ' + lastName as fullName FROM EMPLOYEES WHERE personalID LIKE '8%'
UNION
SELECT firstName + ' ' + lastName as fullName FROM CLIENTS WHERE personalID LIKE '8%'

--Да се изведат номерата на всички семейни стаи, които не с капацитет двама или по-малко души.
SELECT roomNumber FROM ROOMS WHERE roomType LIKE 'Family'
EXCEPT
SELECT roomNumber FROM ROOMS WHERE roomCapacity <= 2

--Да се изведат номерата на всички стаи резервирани през Юли 2019 с изключение на тези направени не от редовни клиенти.
SELECT roomNumber FROM RESERVATIONS WHERE registerDate LIKE '2019-07%'
EXCEPT
SELECT roomNumber FROM RESERVATIONS WHERE clientsNumber IS NULL

--Да се изведат имената на всички редовни клиенти, не живеят в София и са жени.
SELECT firstName + ' ' + lastName as fullName FROM CLIENTS WHERE address NOT LIKE '%Sofia'
INTERSECT
SELECT firstName + ' ' + lastName as fullName FROM CLIENTS WHERE gender LIKE 'F'

--Да се изведат ЕГН-тата на всички служители мъже и на всички служители работещи под 10 часа
SELECT personalID FROM EMPLOYEES WHERE gender LIKE 'M'
INTERSECT
SELECT personalID FROM EMPLOYEES WHERE workingHours < 10