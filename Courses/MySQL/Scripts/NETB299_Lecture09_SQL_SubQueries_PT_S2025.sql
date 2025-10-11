#1:
select
*

from customers c
where c.cnum in (
	select cnum from orders where odate = '20141003'
);


#2:
select
*
from customers

where city in (
	select city from salespeople
    )
order by snum;


#3:

select
*
from customers

where city not in (
	select city from salespeople
    )
order by snum desc;


#4:

select
*
from salespeople

where city in (
	select city from customers
    )
order by city asc;


#5:
select
*
from salespeople

where city not in (
	select city from customers
    );
    
    
#6 - displaying orders*:

select
o.onum as ONUM,
o.amt as AMT,
o.odate as ODATE,
o.cnum as CNUM,
o.snum as SNUM,
o.dcity as CITY 
from orders o

join (
	select cnum, avg(amt) as avg_amt
    from orders
    group by cnum
) as avg_orders
on o.cnum = avg_orders.cnum
where o.amt > avg_orders.avg_amt;

#6A
select
c.cname as CNAME,
o.onum as ONUM,
o.amt as AMT

from orders o
join (
	select cnum, avg(amt) as avg_amt
    from orders
    group by cnum
) as avg_orders on o.cnum = avg_orders.cnum
join customers c on c.cnum = avg_orders.cnum
where o.amt > avg_orders.avg_amt;


#7:

select
ODATE, SUM(AMT)
from orders
group by ODATE
having sum(amt) >= max(amt) + 2000;


#8:
select 
c.CNAME, o.ONUM, o.AMT
from orders o join customers c
on o.cnum = c.cnum 
where o.amt > (select avg(amt) from orders);


#9:
select
c.CNAME,
o.ONUM,
o.ODATE,
o.AMT
from customers c join orders o
	on c.cnum = o.cnum
having o.amt > some (select avg(amt) from orders group by odate); # bad approach





		-- average amount for orders done on the same date

		select odate, avg(amt)
		from orders
		group by odate;
			
			# odate, 				avg(amt)
			-- 2014-10-03 00:00:00, 1788.918000
			-- 2014-10-04 00:00:00, 894.490000
			-- 2014-10-05 00:00:00, 4723.000000
			-- 2014-10-06 00:00:00, 5600.915000

		# Candidates
		# ONUM, AMT, ODATE, CNUM, SNUM, DCITY
		-- 3002, 1900.10, 2014-10-03 00:00:00, 2007, 1004, London
		-- 3005, 5160.45, 2014-10-03 00:00:00, 2003, 1002, London
		-- 3009, 1713.23, 2014-10-04 00:00:00, 2002, 1003, London
		-- 3011, 9891.88, 2014-10-06 00:00:00, 2006, 1001, Barcelona



		select *
		from orders
		order by odate;

		-- Трябва да намерим средна стнст за amt за цял ден и да извадим онези които са над нея за определения ден.
		-- за 05.10 е една единствена стойност - 4723 и при сравнение ще се пропусне (false) защото avg(4723) = 4723;
		-- и 4723 не е > от 4723


# *9
SELECT C.CNAME, O.ONUM, O.ODATE, O.AMT
FROM ORDERS O
JOIN CUSTOMERS C ON O.CNUM = C.CNUM
JOIN (
    SELECT ODATE, AVG(AMT) AS AVG_AMT
    FROM ORDERS
    GROUP BY ODATE
) AS AVG_BY_DATE
ON O.ODATE = AVG_BY_DATE.ODATE
WHERE O.AMT > AVG_BY_DATE.AVG_AMT; -- corelated sub-queries (avg_amt lives outside)

-- Example
SELECT onum, cnum, amt
FROM Orders C1
WHERE C1.amt > (
                SELECT AVG(amt)
				FROM Orders C2
				WHERE C2.cnum = C1.cnum -- c1 lives outside
			);


SELECT ODATE, AVG(AMT) AS AVG_AMT
    FROM ORDERS
    GROUP BY ODATE;
    


#10:
select
odate,
count(*)
from orders o
where amt > (select avg(amt) from orders)
group by odate;


