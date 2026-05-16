-- Create the tables

CREATE TABLE Hotel (
      Hotel_No INT  NOT NULL,
      Name VARCHAR(30)  NOT NULL,
      Address VARCHAR(100)    NOT NULL,
      City VARCHAR(25)  NOT NULL
      CONSTRAINT Hotel_PK PRIMARY KEY(Hotel_No)
);

CREATE TABLE Room (
      Room_No INT   NOT NULL,
      Hotel_No INT   NOT NULL,
      Type VARCHAR(25)  NOT NULL,
      Price DECIMAL(10,2)  NOT NULL
      CONSTRAINT Room_PK PRIMARY KEY(Room_No)
      CONSTRAINT Room_FK FOREIGN KEY (Hotel_No) REFERENCES Hotel(Hotel_No)
);

CREATE TABLE Booking (
      Hotel_No INT  NOT NULL,
      Guest_No INT  NOT NULL,
      Date_From DATE NOT NULL,
      Date_To DATE      NOT NULL,
      Room_No INT NOT NULL
      CONSTRAINT Booking_FK FOREIGN KEY (Hotel_No) REFERENCES Hotel(Hotel_No)
      CONSTRAINT Booking_FK FOREIGN KEY (Guest_No) REFERENCES Guest(Guest_No)
      CONSTRAINT Booking_FK FOREIGN KEY (Room_No) REFERENCES Room(Room_No)
)

CREATE TABLE Guest (
      Guest_No INT  NOT NULL,
      Name VARCHAR(100) NOT NULL,
      Address VARCHAR(100),
      City VARCHAR(25)
      CONSTRAINT Guest_PK PRIMARY KEY Guest(Guest_No)
)

-- Add 5 records for each table (be creative with your data but include a MARRIOT Hotel with a P10,000 per night price)
INSERT INTO Hotel (Hotel_No, Name, Address, City) VALUES
(1, 'Hotel Del Luna', '12 Cheonggyecheon-ro, Jongno-gu', 'Seoul'),
(2, 'MARRIOT Hotel', '7842 Roxas Blvd, Malate', 'Manila'),
(3, 'Century Hotel', '599 Pablo Ocampo St, Malate', 'Manila'),
(4, 'Sofitel', 'CCP Complex, Roxas Boulevard, Pasay', 'Manila'),
(5, 'Meguro Gajoen Hotel', '1-8-1 Shimomeguro, Meguro-ku', 'Tokyo');

INSERT INTO Room (Room_No, Hotel_No, Type, Price) VALUES
(304, 1, 'Deluxe', 12000),
(421, 2, 'Single', 9000),
(556, 3, 'Standard', 8000),
(209, 4, 'Double', 7000),
(108, 5, 'Presidential', 35000);

INSERT INTO Booking (Hotel_No, Guest_No, Date_From, Date_To, Room_No) VALUES
(1, 10, '2025-04-10', '2025-05-10', 304),
(2, 11, '2025-10-12', '2025-10-13', 421),
(3, 12, '2025-06-03', '2025-06-08', 556),
(4, 13, '2025-08-05', '2025-08-15', 209),
(5, 14, '2025-07-24', '2025-07-28', 108);

INSERT INTO Guest (Guest_No, Name, Address, City) VALUES
(10, 'Jang Man Wol', 'Seoul, KR', 'Seoul'),
(11, 'Tanggol Martin', 'Quiapo, PH', 'Manila'),
(12, 'Sandara Park', 'Busan, KR', 'Busan'),
(13, 'Antonio Luna', 'Binondo, PH', 'Manila'),
(14, 'Henry Sy', 'Xiamen, CN', 'Xiamen');

-- 1. List all names of hotels.
SELECT Name 
FROM Hotel;

-- 2. List all single rooms with a price below P10,000 per night.
SELECT Room_No 
FROM Room
WHERE "Type" = 'Single'
     AND "Price" < 10000;

-- 3. List the names and addresses of all guests.
SELECT "Name", "Address" 
FROM Guest;

-- 4. List the price and the type of all rooms at the Marriot Hotel.
SELECT "Price", "Type" 
FROM Room WHERE Hotel_No = (
     SELECT Hotel_No 
     FROM Hotel
     WHERE Name = 'MARRIOT Hotel'
)

-- 5.List the details of all rooms at the Marriot Hotel, including the name of the guests staying in the room if the room is occupied.
SELECT "r.Room_No", "r.Type", "r.Price",
    SELECT(
        g.Name FROM Guest g
        WHERE g.Guest_No = (
            SELECT b.Guest_No 
            FROM Booking b
            WHERE b.Room_No = r.Room_No
        ) 
     ) AS Guest_Name
FROM Room r
WHERE r.Hotel_No = (
    SELECT Hotel_No
    FROM Hotel
    WHERE Name = 'MARRIOT Hotel'
);