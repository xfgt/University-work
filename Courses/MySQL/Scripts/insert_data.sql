-- insert_data.sql

-- Insert data into salespeople
INSERT INTO salespeople (Snum, Sname, City, Comm) VALUES
(1001, 'Peel', 'London', 0.12),
(1002, 'Serres', 'San Jose', 0.13),
(1004, 'Motika', 'London', 0.11),
(1007, 'Rifkin', 'Barcelona', 0.15),
(1003, 'Axelrod', 'New York', 0.10),
(1020, 'Wang', 'Bangkok', 0.11);

-- Insert data into customers
INSERT INTO customers (Cnum, Cname, City, Rating, Snum) VALUES
(2001, 'Hoffman', 'London', 100, 1001),
(2002, 'Giovanni', 'Rome', 200, 1003),
(2003, 'Lui', 'San Jose', 200, 1002),
(2004, 'Grass', 'Berlin', NULL, 1002),
(2006, 'Clemens', 'London', NULL, 1001),
(2007, 'Pereira', 'Rome', 100, 1004),
(2008, 'Cisneros', 'San Jose', 300, 1007),
(2009, 'Doe', 'Shangri-La', 0, 1001);

-- Insert data into orders
INSERT INTO orders (Onum, Amt, Odate, Cnum, Snum, Dcity) VALUES
(3001, 18.69, '2014-10-03', 2008, 1007, 'London'),
(3002, 1900.10, '2014-10-03', 2007, 1004, 'London'),
(3003, 767.19, '2014-10-03', 2001, 1001, 'Barcelona'),
(3005, 5160.45, '2014-10-03', 2003, 1002, 'London'),
(3006, 1098.16, '2014-10-03', 2008, 1007, 'Madrid'),
(3007, 75.75, '2014-10-04', 2002, 1002, 'London'),
(3008, 4723.00, '2014-10-04', 2004, 1002, 'London'),
(3009, 1713.23, '2014-10-04', 2002, 1003, 'London'),
(3010, 1309.95, '2014-10-04', 2004, 1002, 'London'),
(3011, 9891.88, '2014-10-06', 2006, 1001, 'Barcelona');
