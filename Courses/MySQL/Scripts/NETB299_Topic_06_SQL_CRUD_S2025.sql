
-- Script Name: NETB299_Topic_06_SQL_CRUD_S2025.sql

DROP TABLE IF EXISTS People;

CREATE TABLE People (
    FName VARCHAR(50),
    LName VARCHAR(50),
    Age INT,
    Car VARCHAR(50),
    Color VARCHAR(50)
);

INSERT INTO People (FName, LName, Age, Car, Color) VALUES
('John', 'Smith', 35, 'BMW', 'Red'),
('Mary', 'Shelley', 29, 'Mini', 'Black'),
('John', 'Doe', 45, 'Audi', 'White'),
('Nicky', 'Little', 25, 'BMW', 'White'),
('Peter', 'White', 30, 'Reno', 'Red'),
('Nicky', 'Black', 27, 'Seat', 'Green');
