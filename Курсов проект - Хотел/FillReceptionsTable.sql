USE Hotel;

--Insert some example values in the RESERVATIONS table

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,packet)
VALUES('2020-03-14','2020-03-16',125,'Ivana Petkova','RO')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,packet)
VALUES('2019-12-01','2019-12-05',404,'Hristo Velev','BB')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,packet)
VALUES('2019-07-28','2019-08-05',512,'Georgi Kovachev','AI')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,packet)
VALUES('2020-02-14','2020-02-15',103,'Petar Georgiev','BB')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,packet)
VALUES('2020-01-30','2020-02-01',222,'Daniela Cvetkova','HB')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2020-01-21','2020-01-23',320,5,'RO')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2020-03-10','2020-03-15',110,15,'RO')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2020-04-04','2020-04-10',502,1,'AI')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2019-09-26','2019-09-28',206,10,'HB')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2019-08-01','2019-08-10',414,3,'AI')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2020-03-06','2020-03-08',315,18,'BB')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2020-01-21','2020-01-23',120,2,'RO')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,packet)
VALUES('2019-07-28','2019-07-31',125,'Ivana Petkova','RO')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,packet)
VALUES('2019-07-10','2019-07-15',404,'Hristo Velev','BB')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,packet)
VALUES('2019-09-12','2019-09-15',512,'Georgi Kovachev','AI')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,packet)
VALUES('2019-07-15','2019-07-18',103,'Petar Georgiev','BB')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsName,packet)
VALUES('2019-07-01','2019-07-06',222,'Daniela Cvetkova','HB')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2019-09-10','2019-09-15',320,5,'RO')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2019-07-05','2019-07-12',110,15,'RO')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2019-07-03','2019-07-10',502,1,'AI')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2019-07-02','2019-07-06',206,10,'HB')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2019-07-12','2019-07-19',414,3,'AI')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2019-07-29','2019-08-02',315,18,'BB')

INSERT INTO RESERVATIONS(registerDate,checkOutDate,roomNumber,clientsNumber,packet)
VALUES('2019-06-29','2019-07-02',120,2,'RO')


UPDATE RESERVATIONS SET priceForNight = 
(SELECT ROOMS.priceForNight FROM ROOMS WHERE RESERVATIONS.roomNumber = ROOMS.roomNumber) + 
(SELECT PACKAGES.additionalPrice FROM PACKAGES WHERE RESERVATIONS.packet = PACKAGES.package)

UPDATE RESERVATIONS SET clientsName = 
(SELECT CLIENTS.firstName + ' ' + CLIENTS.lastName FROM CLIENTS WHERE RESERVATIONS.clientsNumber = CLIENTS.clientsNumber)
WHERE clientsNumber IS NOT NULL

SELECT * FROM RESERVATIONS
