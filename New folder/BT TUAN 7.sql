use classicmodels;

-- 1
select concat(employees.lastName, ' ', employees.firstName) as fullname, offices.addressLine1,
offices.addressLine2
from employees inner join offices on employees.officeCode = offices.officeCode;

-- 2
select c.customernumber, c.customerName, p.productname
from customers c inner join orders o on c.customernumber = o.customernumber
inner join orderdetails od on od.ordernumber = o.ordernumber
inner join products p on p.productcode = od.productcode;

-- 3
select p.productcode, p.productline, o.ordernumber
from products p left join orderdetails od on p.productcode = od.productcode
left join orders o on o.ordernumber = od.ordernumber
where o.ordernumber is null;

-- 4
select * from orderdetails;

select o.orderDate, o.requiredDate, o.status, sum(od.quantityOrdered*od.priceEach) as total
from orders o inner join orderdetails od on o.ordernumber = od.ordernumber
where year(o.orderdate) = 2005 and month(o.orderdate) = 3
group by od.ordernumber;

-- 5
select * from products;

select pl.productline, sum(p.quantityinstock) as total
from products p inner join productlines pl on pl.productline = p.productline
group by pl.productline
order by sum(p.quantityInStock) desc;