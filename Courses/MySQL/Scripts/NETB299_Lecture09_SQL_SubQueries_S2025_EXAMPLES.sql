# List all orders placed by Lui

select *
from orders
where cnum = (
	select cnum from customers where cname = 'Lui'
);

-- subquery
	select cnum from customers where cname = 'Lui';
    
    
    
# List orders with amount less the average amount of orders done on october 4

select *
from orders
where amt < (
	select avg(amt) from orders where odate = '20141004'
);

-- subquery
select avg(amt) from orders where odate = '20141004';





# Count customers which rating is greater than 
# the average rating of the customers from San Jose

select rating, count(cnum)
from customers
group by rating
having rating > (
	select avg(rating) from customers where city = 'San Jose'
);

-- subquery
	select avg(rating) from customers where city = 'San Jose';
    
    
# ALL, SOME, ANY

-- ANY and SOME are equivalent.
-- They link a simple relational operator with the sub-query.
-- The relational operator is applied to each row of the result of the sub-query.

-- The logical expression is true
-- iff one or more (at least one) rows in the sub-query result satisfy the comparison.


-- ALL is true iff the relevant comparison is true for each and every value 
-- in the sub-query result.

# EXISTS AND NOT EXISTS

-- EXISTS is true iff there exists at least one row in the sub-query result
-- and the result rows may have more than one column

-- NOT EXISTS is truee' if there are no rows in the query result (returned dataset is empty)
-- ' truee - true and only true


#1
select distinct cnum, amt
from orders
where amt > any ( select amt  from orders where cnum = 2004)
order by amt;
-- with "some" is the same


-- each value for amount is compared to be larger EITHER than 75.75 or 1309.95
-- so there would exist values LARGER THAN THE LOWEST - 75.75 and 1309.95 or higher

select distinct cnum, amt
from orders
where amt > all (select amt from orders where cnum = 2004);

-- with "all" each value for amt gets compared with the largest amt from the sub-query
-- that is 1309.95
-- so the output is all values larger than 1309.95


-- sub-query 
select amt  from orders where cnum = 2004;
-- output:
 # amt
-- 75.75
-- 1309.95



# 2 in

select *
from orders 
where snum in (
	select snum from salespeople where city = 'London'
);

-- sub-query
select snum from salespeople where city = 'London';


#3
select
*
from orders
where amt > (
	select amt from orders where odate = '20141005' -- 4723
) AND 
snum IN (
	select snum from salespeople where city = 'London'
); -- 1001, 1004

-- sub-queries
select amt from orders where odate = '20141005';
select snum from salespeople where city = 'London';


# 3
select
*
from orders
where cnum IN (
	select cnum from customers where city = (
		select city from salespeople where sname = 'Motika'
	)
); -- 2001, 2006

-- sub-queries

select city from salespeople where sname = 'Motika';
select cnum from customers where city = 'London';



# corelated sub-queries 

-- Some sub-queries are independent of their outer (parent) query;
-- They return the same result any time they are evaluated.

-- The result of other sub-queries, _correlated_, depends on the row being processed by the other query:

#	- the sub-query result varies with the row being processed by the outer query;
#	- the sub-query must be re-evaluated for each row of the outer query;
#	- processing time of correlated sub-queries is theoreticaly equal of joins, but practically
# much higher (when join combines tables according to fields, which they are indexed)



#4
select onum, cnum, amt
from orders C1 -- we give an alias "C1"
where C1.amt > (
	
		select avg(amt)
        from orders C2 -- we give an alias "C2"
        where C2.cnum = C1.cnum -- we use the outer alias "C1" inside
        
    
);


# 5 - Display the total amount of all orders grouped by order date that are at least $2000 greater than the maximum order placed on the same date.
SELECT odate, SUM(amt)
FROM Orders O1
GROUP BY odate
HAVING SUM(amt) > (
	SELECT 2000 + MAX(amt) FROM ORDERS O2 WHERE O2.odate = O1.odate
);


# 6 - Display the customers who are from the same city with one or more salespeople.
SELECT *
FROM Customers C
WHERE EXISTS (
	SELECT *
	FROM Salespeople S
    WHERE S.city = C.city
);




