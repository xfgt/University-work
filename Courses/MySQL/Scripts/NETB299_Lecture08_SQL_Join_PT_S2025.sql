select *
from customers
join orders
join salespeople;


#1:
SELECT  x.ONUM, y.CNAME
FROM orders x
JOIN customers y ON x.CNUM = y.CNUM
order by x.onum;


#2:
select 
c.cname, 
s.sname, 
s.comm
	from customers c
	join salespeople s
		on c.snum = s.snum
having s.comm > 0.12;



#3:
select 
c.cname, 
s.sname, 
round(s.comm * o.amt, 4) as "COMMISSION_AMOUNT"

from customers c
	join orders o 
	on c.cnum = o.cnum
		join salespeople s 
		on o.snum = s.snum

where c.rating > 100
order by s.sname desc;

 
#4:
select 
s1.sname as SNAME, 
s2.sname as SNAME

	from salespeople s1 join salespeople s2
		on 		s1.city = s2.city 
		and 	s1.sname < s2.sname;


#5:
select
c.cname as CNAME,
c.city as CITY
from customers c
where rating = (select rating from customers where cname="Hoffman") and c.cname != "Hoffman";


#6:
select 
 c.city as CITY,
 SUM(o.amt) as TOTAL_AMOUNT

from customers c join orders o
	on c.cnum = o.cnum and c.snum = o.snum
    
    OR c.cnum = o.cnum and c.city = o.dcity -- 4723
group by c.city;


#6a:
select 
o.dcity as DCITY,
sum(o.amt) as TOTAL_AMOUNT
from orders o join customers c
	on c.cnum = o.cnum and c.city = o.dcity;


#7:
select 
s.sname as SNAME,
c.cname as CNAME,
o.amt as AMT

from customers c join orders o
	
    on c.cnum = o.cnum and c.snum != o.snum
    
		join salespeople s
		on o.snum = s.snum;


#8:

select 
 s.sname as SNAME,
 c.cname as CNAME,
 o.amt as AMT

from salespeople s join customers c join orders o
	on o.snum = s.snum 
    and o.snum = c.snum 
    and c.cnum = o.cnum 
    
order by s.sname;


#9:
select
c.cname as CNAME,
avg (o.amt) as "AVG(AMT)"

from customers c join orders o
	on c.cnum = o.cnum

where amt > 2500
group by c.cname;



#10:


select
s.sname as SNAME
from salespeople s left join customers c
	on s.snum = c.snum 
    
	Where s.snum not IN (
			select s.snum from salespeople s join customers c on s.snum = c.snum
	)
group by s.snum;



