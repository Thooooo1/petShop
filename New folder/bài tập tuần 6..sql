-- 1.Đưa ra tên các thành phố và số lượng khách hàng từng thành phố.
use classicmodels;
select city, count(customerNumber) as slkhach
from customers
group by city;
-- 2.Đưa ra số lượng các đơn dặt hàng trong tháng 3 của năm 2005.
select count(*) as sldon
from orders
where year(orderDate) =2005 and month(orderDate)=3;
-- 3.Đưa ra số lượn các đơn đặt hàng trong từng tháng cảu năm 2005.
select month(orderDate), count(*) as totalOrder
from orders
where year(orderDate) =2005
group by month (orderDate); 
-- 4 Đưa ra 10 mã đơn hàng có giá trị lớn nhất.
select orderNumber, sum(quantityOrdered*priceEach) as TotlaOrderNumber
from orderdetails
group by orderNumber
order by sum(quantityOrdered*priceEach) desc 
limit 10;
-- 5.Đưa ra mã nhóm hàng và tổng số lượng hàng hóa còn trong kho của nhóm đo.
select productLine, sum(quantityInStock) as TotalInStock
from products
group by productLine;
