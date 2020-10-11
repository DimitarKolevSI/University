USE Hotel

CREATE TABLE ROOMS(
	roomNumber INT,
	floor INT,
	status CHAR(1) DEFAULT 'F',
	roomCapacity INT,
	roomType VARCHAR(10),
	priceForNight DECIMAL(8,2)
);

CREATE TABLE RESERVATIONS(
	registerDate DATE,
	checkOutDate DATE,
	roomNumber INT,
	reservationNumber INT IDENTITY(1,1),
	clientsName VARCHAR(60),
	priceForNight DECIMAL(8,2),
	totalPrice AS (priceForNight * DATEDIFF(DAY,registerDate,checkOutDate)) PERSISTED,
	clientsNumber INT,
	packet CHAR(2)
);

CREATE TABLE CLIENTS(
	firstName VARCHAR(20),
	secondName VARCHAR(20),
	lastName VARCHAR(20),
	personalID CHAR(10),
	IDCardNumber CHAR(9),
	address VARCHAR(100),
	gender CHAR(1),
	clientsNumber INT IDENTITY(1,1)
);

CREATE TABLE EMPLOYEES(
	firstName VARCHAR(20),
	secondName VARCHAR(20),
	lastName VARCHAR(20),
	personalID CHAR(10),
	type VARCHAR(15),
	insuranceNumber VARCHAR(20),
	workingHours INT,
	gender CHAR(1),
	employeeID INT IDENTITY(1,1),
	salary DECIMAL(10,2)
);

CREATE TABLE PACKAGES(
	package CHAR(2),
	additionalPrice INT
);