#1:
SELECT onum, amt, odate FROM orders;


#2:
SELECT cnum, cname, city, rating, snum FROM customers
WHERE SNUM = 1001;


#3:
SELECT city, sname, snum, comm FROM salespeople;


#4:
SELECT DISTINCT SNUM FROM orders
ORDER BY onum;


#5:
SELECT SNAME, CITY FROM salespeople
WHERE city = 'London' AND comm > 0.1;


#6:
SELECT * FROM customers
WHERE rating <= 100 OR city = 'Rome';


#7.1:
SELECT * FROM orders
WHERE odate >= '2014-10-03' AND
odate <= '2014-10-04';


#7.2:
SELECT * FROM orders
WHERE odate BETWEEN '2014-10-03' AND'2014-10-04';

#8:
SELECT * FROM CUSTOMERS
WHERE  cname BETWEEN 'A' AND 'H';


#9:
SELECT * FROM CUSTOMERS
WHERE cname LIKE 'C%' OR 'c%';


#10:
SELECT * FROM ORDERS
WHERE amt = 0 OR amt = NULL;


#11:
SELECT COUNT(*) AS "Number of orders" FROM ORDERS
WHERE ODATE = '2014-10-03';


#12:
SELECT COUNT(DISTINCT CITY) AS "Distinct cities"
FROM Customers;


#13:
SELECT CNAME AS "First Customer" FROM CUSTOMERS 
WHERE CNAME LIKE 'G%' 
ORDER BY CNAME ASC
LIMIT 1 ;


#14:
select * from orders
where odate between '2014-10-03' and '2014-10-04'
or dcity = 'Barcelona';


#15:
SELECT onum, amt, dcity FROM orders
WHERE (amt > 3000 AND AMT < 5000) AND 
(DCITY = 'London' OR DCITY = 'Barcelona');