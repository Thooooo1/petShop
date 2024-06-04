use classicmodels;
select * from customers where city in('Nantes','Lyon');
select * from orders where shippedDate between '2003-1-10' and '2003-3-10';
select *from productlines where productLine like 'CARS';
select  productName, quantityInStock from products order by quantityInstock desc limit 10;
select  productName, productline,(quantityInStock * buyPrice) as inventoryValue from products;