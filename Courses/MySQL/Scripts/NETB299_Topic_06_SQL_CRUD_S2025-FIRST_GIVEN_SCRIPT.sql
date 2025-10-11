-- SQLINES DEMO *** S2025
-- SQLINES DEMO *** eation scheme script.

-- SQLINES DEMO *** S2025.SQL


-- SQLINES DEMO *** e S2025


-- SQLINES DEMO *** ECTS




-- SQLINES DEMO *** TABLES SALESPEOLE, CUSTOMERS, ORDERS, AND VIEW SUMMARY

-- SQLINES FOR EVALUATION USE ONLY (14 DAYS)
CREATE TABLE SALESPEOPLE ( 
	`SNUM`       SMALLINT NOT NULL, 
    `SNAME`      VARCHAR(10), 
    `CITY`       VARCHAR(10), 
    `COMM`       DECIMAL(3,2), 
    /* Name ignored: constraint  `SALESPEOPLE_PK` */ primary key (`SNUM`) 
) ;

CREATE TABLE `CUSTOMERS` ( 
    `CNUM`       SMALLINT NOT NULL, 
    `CNAME`      VARCHAR(10), 
    `CITY`       VARCHAR(10), 
    `RATING`     SMALLINT, 
    `SNUM`       SMALLINT, 
    /* Name ignored: constraint  `CUSTOMERS_PK` */ primary key (`CNUM`) 
) ;


-- creating a connection between two tables 

ALTER TABLE `CUSTOMERS` ADD CONSTRAINT 	`CUSTOMERS_FK` -- modify the table "Customers"
FOREIGN KEY (`SNUM`) REFERENCES `SALESPEOPLE` (`SNUM`) 
-- add an index called "CUSTOMERS_FK" which is foregin key to SNUM
-- to know which SNUM we are talking about, we are talking about the reference in SALESPEOPLE called "SNUM"
;

CREATE TABLE `ORDERS` (  
    `ONUM`       SMALLINT NOT NULL,  
    `AMT`        DECIMAL(7,2),  
    `ODATE`      DATETIME,  
    `CNUM`       SMALLINT,  
    `SNUM`       SMALLINT,  
    `DCITY`       VARCHAR(10), 
    /* Name ignored: constraint  `ORDERS_PK1` */ primary key (`ONUM`)  
) ;

ALTER TABLE `ORDERS` ADD CONSTRAINT `ORDERS_FK` 
FOREIGN KEY (`CNUM`) REFERENCES `CUSTOMERS` (`CNUM`) ;

ALTER TABLE `ORDERS` ADD CONSTRAINT `ORDERS_FK1` 
FOREIGN KEY (`SNUM`) REFERENCES `SALESPEOPLE` (`SNUM`);




-- PART FOR CREATING A VIEW 
CREATE VIEW summary AS
SELECT onum, amt, odate, cname, sname, orders.dcity AS dcity
           FROM salespeople INNER JOIN orders USING(snum)
           INNER JOIN customers USING(cnum)
ORDER BY 1;





-- SQLINES DEMO *** SALESPEOPLE TABLE


INSERT INTO salespeople VALUES(1001,'Peel','London',0.12);

INSERT INTO salespeople VALUES(1002,'Serres','San Jose',0.13);

INSERT INTO salespeople VALUES(1004,'Motika','London',0.11);

INSERT INTO salespeople VALUES(1007,'Rifkin','Barcelona',0.15);

INSERT INTO salespeople VALUES(1003,'Axelrod','New York',0.1);

INSERT INTO salespeople VALUES(1020,'Wang','Bangkok',0.11);

-- SQLINES DEMO *** CUSTOMERS TABLE


INSERT INTO customers VALUES(2001,'Hoffman','London',100,1001);

INSERT INTO customers VALUES(2002,'Giovanni','Rome',200,1003);

INSERT INTO customers VALUES(2003,'Lui','San Jose',200,1002);

INSERT INTO customers VALUES(2004,'Grass','Berlin',300,1002);

INSERT INTO customers VALUES(2006,'Clemens','London',null,1001);

INSERT INTO customers VALUES(2007,'Pereira','Rome',100,1004);

INSERT INTO customers VALUES(2008,'Cisneros','San Jose',300,1007);

INSERT INTO customers VALUES(2009,'Doe','Shangri-La',0,1001);

-- SQLINES DEMO *** ORDERS TABLE


INSERT INTO orders VALUES(3001,18.69,STR_TO_DATE('2014-10-03', '%Y-%m-%d'),2008,1007,'London');

INSERT INTO orders VALUES(3002,1900.1,STR_TO_DATE('2014-10-03', '%Y-%m-%d'),2007,1004,'London');

INSERT INTO orders VALUES(3003,767.19,STR_TO_DATE('2014-10-03', '%Y-%m-%d'),2001,1001,'Barcelona');

INSERT INTO orders VALUES(3005,5160.45,STR_TO_DATE('2014-10-03', '%Y-%m-%d'),2003,1002,'London');

INSERT INTO orders VALUES(3006,1098.16,STR_TO_DATE('2014-10-03', '%Y-%m-%d'),2008,1007,'Madrid');

INSERT INTO orders VALUES(3007,75.75,STR_TO_DATE('2014-10-04', '%Y-%m-%d'),2004,1002,'London');

INSERT INTO orders VALUES(3008,4723,STR_TO_DATE('2014-10-05', '%Y-%m-%d'),2006,1002,'London');

INSERT INTO orders VALUES(3009,1713.23,STR_TO_DATE('2014-10-04', '%Y-%m-%d'),2002,1003,'London');

INSERT INTO orders VALUES(3010,1309.95,STR_TO_DATE('2014-10-06', '%Y-%m-%d'),2004,1002,'London');

INSERT INTO orders VALUES(3011,9891.88,STR_TO_DATE('2014-10-06', '%Y-%m-%d'),2006,1001,'Barcelona');



