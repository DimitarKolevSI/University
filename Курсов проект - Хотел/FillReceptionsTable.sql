USE Hotel;

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,packet)
VALUES('2020-03-14','2020-03-16',125,'Ivana Petkova',90,'None')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,packet)
VALUES('2019-12-01','2019-12-05',404,'Hristo Velev',120,'Breakfast')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,packet)
VALUES('2019-07-28','2019-08-05',512,'Georgi Kovachev',180,'All-inclusive')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,packet)
VALUES('2020-02-14','2020-02-15',103,'Petar Georgiev',90,'Breakfast')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,packet)
VALUES('2020-01-30','2020-02-01',222,'Daniela Cvetkova',100,'Breakfast and Dinner')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,clientsNumber,packet)
VALUES('2020-01-21','2020-01-23',320,(Select firstname + lastname from client where clientsNumber like 5 ) ,110,5,'None')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,clientsNumber,packet)
VALUES('2020-03-10','2020-03-15',110,(Select firstname + lastname from client where clientsNumber like 15),90,15,'None')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,clientsNumber,packet)
VALUES('2020-04-04','2020-04-10',502,(Select firstname + lastname  from client where clientsNumber like 1),180,1,'All-inclusive')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,clientsNumber,packet)
VALUES('2019-09-26','2019-09-28',206,(Select firstname + lastname from client where clientsNumber like 10),100,10,'Dinner')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,clientsNumber,packet)
VALUES('2019-08-01','2019-08-10',414,(Select firstname +lastname from client where clientsNumber like 3),120,3,'All-inclusive')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,clientsNumber,packet)
VALUES('2020-03-06','2020-03-08',315,(Select firstname + lastname from client where clientsNumber like 18),100,18,'Breakfast')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,priceForNight,clientsNumber,packet)
VALUES('2020-01-21','2020-01-23',120,(Select firstname + lastname from client where clientsNumber like 2 ) ,110,2,'None')

select * from RESERVATIONS

UPDATE RESERVATIONS SET registerDate = '2019-07-28', checkOutDate = '2019-07-31' WHERE reservationNumber = 23
UPDATE RESERVATIONS SET registerDate = '2019-07-10', checkOutDate = '2019-07-15' WHERE reservationNumber = 24
UPDATE RESERVATIONS SET registerDate = '2019-09-12', checkOutDate = '2019-09-15' WHERE reservationNumber = 25
UPDATE RESERVATIONS SET registerDate = '2019-07-15', checkOutDate = '2019-07-18' WHERE reservationNumber = 26
UPDATE RESERVATIONS SET registerDate = '2019-07-01', checkOutDate = '2019-07-06' WHERE reservationNumber = 27
UPDATE RESERVATIONS SET registerDate = '2019-09-10', checkOutDate = '2019-09-15' WHERE reservationNumber = 28
UPDATE RESERVATIONS SET registerDate = '2019-07-05', checkOutDate = '2019-07-12' WHERE reservationNumber = 29
UPDATE RESERVATIONS SET registerDate = '2019-07-03', checkOutDate = '2019-07-10' WHERE reservationNumber = 30
UPDATE RESERVATIONS SET registerDate = '2019-07-02', checkOutDate = '2019-07-06' WHERE reservationNumber = 31
UPDATE RESERVATIONS SET registerDate = '2019-07-12', checkOutDate = '2019-07-19' WHERE reservationNumber = 32
UPDATE RESERVATIONS SET registerDate = '2019-07-29', checkOutDate = '2019-08-02' WHERE reservationNumber = 33
UPDATE RESERVATIONS SET registerDate = '2019-06-29', checkOutDate = '2019-07-02' WHERE reservationNumber = 34
UPDATE RESERVATIONS SET priceForNight = 90 WHERE roomNumber = 120
