-- create_tables.sql

-- Create table: salespeople
CREATE TABLE salespeople (
    Snum INT(4) PRIMARY KEY,
    Sname VARCHAR(10),
    City VARCHAR(10),
    Comm FLOAT(3,2)
);

-- Create table: customers
CREATE TABLE customers (
    Cnum INT(4) PRIMARY KEY,
    Cname VARCHAR(10),
    City VARCHAR(10),
    Rating INT(11),
    Snum INT(4),
    FOREIGN KEY (Snum) REFERENCES salespeople(Snum)
);

-- Create table: orders
CREATE TABLE orders (
    Onum INT(4) PRIMARY KEY,
    Amt FLOAT(6,2),
    Odate DATE,
    Cnum INT(4),
    Snum INT(4),
    Dcity VARCHAR(10),
    FOREIGN KEY (Cnum) REFERENCES customers(Cnum),
    FOREIGN KEY (Snum) REFERENCES salespeople(Snum)
);

-- Optional: Create summary as a view
CREATE VIEW summary AS
SELECT 
    o.Onum,
    o.Amt,
    o.Odate,
    c.Cname,
    s.Sname,
    o.Dcity
FROM orders o
JOIN customers c ON o.Cnum = c.Cnum
JOIN salespeople s ON o.Snum = s.Snum;
