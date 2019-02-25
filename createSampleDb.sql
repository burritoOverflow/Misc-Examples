CREATE TABLE `Orders` (
	`OrderNumber`	INTEGER,
	`OrderDate`	TEXT,
	`CustomerID`	INTEGER,  -- primary key for customer table
	`SerialNum`	INTEGER,    -- primary key for Machines table
	PRIMARY KEY(`OrderNumber`)
);

CREATE TABLE `Customers` (
	`CustID`	INTEGER,
	`Name`	TEXT,
	`PhoneNumber`	TEXT,
	`Street`	TEXT,
	`City`	TEXT,
	`State`	TEXT,
	`Zip`	INTEGER,
	PRIMARY KEY(`CustID`)
);

CREATE TABLE `Machines` (
	`SerialNum`	INTEGER, -- pertains to each individual machine
	`ModelNum`	INTEGER, -- primary key for models table
	PRIMARY KEY(`SerialNum`)
);

CREATE TABLE `Model` (
	`ID`	INTEGER,
	`Speed`	REAL,
	`RAM`	INTEGER,
	`HD`	INTEGER,
	`Price`	REAL,
	`MfrID`	INTEGER, -- primary key for Manufacturer table, we'll make this 6 digits
	PRIMARY KEY(`ID`)
);

CREATE TABLE `Manufacturer` (
	`ID`	INTEGER,              -- 6 digits, see above
	`Name`	TEXT,
	`PhoneNum`	TEXT,
	`EmailAddress`	TEXT,
	PRIMARY KEY(`ID`)
);


INSERT INTO Orders(OrderNumber, OrderDate, CustomerID, SerialNum) VALUES (17743, "2011-01-17", 315, 3304);

INSERT INTO Orders(OrderNumber, OrderDate, CustomerID, SerialNum) VALUES (17760,
"2012-03-24", 322, 9054);

INSERT INTO Orders(OrderNumber, OrderDate, CustomerID, SerialNum) VALUES (17781,
"2013-02-15", 303, 7812);

INSERT INTO Orders(OrderNumber, OrderDate, CustomerID, SerialNum) VALUES (17787,
"2015-04-18", 373, 6573);

INSERT INTO Orders(OrderNumber, OrderDate, CustomerID, SerialNum) VALUES (17741,
"2013-10-11", 171, 5412);

INSERT INTO Orders(OrderNumber, OrderDate, CustomerID, SerialNum) VALUES (17755,
"2018-10-12", 322, 6573);

INSERT INTO Orders(OrderNumber, OrderDate, CustomerID, SerialNum) VALUES (17712,
"2017-10-05", 303, 9054);

INSERT INTO Orders(OrderNumber, OrderDate, CustomerID, SerialNum) VALUES (17798,
"2007-07-05", 907, 6573);


INSERT INTO Customers(CustID, Name, PhoneNumber, Street, City, State, Zip)
VALUES (315, 'Todd Sanswick', '219-431-3276', '12 Pennrose Ln', 'Burbank', 'CA', 90212);

INSERT INTO Customers(CustID, Name, PhoneNumber, Street, City, State, Zip)
VALUES (322, 'Gail Vanderhooven', '212-431-7876', '121 Pennrose Rd', 'San Fernando', 'CA', 90714);

INSERT INTO Customers(CustID, Name, PhoneNumber, Street, City, State, Zip)
VALUES (303, 'Sarah Sanders', '313-421-7116', '305 Burbank Rd', 'San Diego', 'CA', 92918);

INSERT INTO Customers(CustID, Name, PhoneNumber, Street, City, State, Zip)
VALUES (373, 'Michael Birbiglia', '809-421-1738', '303 Vineland Dr', 'Los Angeles', 'CA', 90210);

INSERT INTO Customers(CustID, Name, PhoneNumber, Street, City, State, Zip)
VALUES (171, 'RJ Verbeek', '973-222-2143', '17 DumDrive', 'Montpilar', 'VT', 90210);

INSERT INTO Customers(CustID, Name, PhoneNumber, Street, City, State, Zip)
VALUES (907, 'Adam Smith', '310-431-2143', '41 Crenshaw Blvd', 'Los Angeles', 'CA', 90107);

INSERT INTO Machines(SerialNum, ModelNum) VALUES(3304, 99);

INSERT INTO Machines(SerialNum, ModelNum) VALUES(9054, 69);

INSERT INTO Machines(SerialNum, ModelNum) VALUES(7812, 49);

INSERT INTO Machines(SerialNum, ModelNum) VALUES(6573, 36);

INSERT INTO Machines(SerialNum, ModelNum) VALUES(5412, 72);

INSERT INTO Machines(SerialNum, ModelNum) VALUES(1713, 81);


INSERT INTO Model(ID, Speed, RAM, HD, Price, MfrID) VALUES(99, 2.34, 8, 128, 1050.99, 143098);

INSERT INTO Model(ID, Speed, RAM, HD, Price, MfrID) VALUES(69, 3.1, 16, 500, 1800.00, 784321);

INSERT INTO Model(ID, Speed, RAM, HD, Price, MfrID) VALUES(49, 2.7, 8, 256, 999.00, 124786);

INSERT INTO Model(ID, Speed, RAM, HD, Price, MfrID) VALUES(36, 3.1, 16, 500, 1100.00, 347896);

INSERT INTO Model(ID, Speed, RAM, HD, Price, MfrID) VALUES(72, 2.9, 8, 256, 800.00, 541678);

INSERT INTO Model(ID, Speed, RAM, HD, Price, MfrID) VALUES(81, 1.9, 4, 128, 650.00, 124786);


INSERT INTO Manufacturer(ID, Name, PhoneNum, EmailAddress) VALUES(143098, 'Zoop', '310-324-7816',
'deanW31@zoop.org');

INSERT INTO Manufacturer(ID, Name, PhoneNum, EmailAddress) VALUES(784321, 'World', '264-411-3134',
'worldCom31@world.org');

INSERT INTO Manufacturer(ID, Name, PhoneNum, EmailAddress) VALUES(124786, 'BigTech', '312-543-3155', 'admin@bigtech.org');

INSERT INTO Manufacturer(ID, Name, PhoneNum, EmailAddress) VALUES(347896, 'GlobeTech', '431-321-5543', 'globe@GlobeTech.org');

INSERT INTO Manufacturer(ID, Name, PhoneNum, EmailAddress) VALUES(541678, 'ShinyComps', '431-764-9078', 'shine@shinyComps.org');
