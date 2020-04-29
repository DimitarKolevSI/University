USE Hotel


CREATE TABLE ROOM(
	roomNumber INT,
	floor INT,
	status CHAR(1) DEFAULT 'F',
	roomCapacity INT,
	roomType VARCHAR(10)
);

CREATE TABLE RESERVATIONS(
	registerDate DATE,
	checkOutDate DATE,
	roomNumber INT,
	reservationNumber INT IDENTITY(1,1),
	clientsName VARCHAR(60),
	priceForNight DECIMAL(8,2),
	clientsNumber INT,
	packet VARCHAR(50)
);

CREATE TABLE CLIENT(
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