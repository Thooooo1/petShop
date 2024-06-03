use classicmodels;
SELECT DISTINCT productCode
FROM orderdetails
WHERE orderNumber IN (
SELECT orderNumber
FROM orders
WHERE YEAR(orderDate) = 2005 AND MONTH(orderDate) = 3
);

SELECT DISTINCT od.productCode
FROM orderdetails od
INNER JOIN orders o ON od.orderNumber = o.orderNumber
WHERE YEAR(o.orderDate) = 2005 AND MONTH(o.orderDate) = 3;

SELECT *
FROM orders
WHERE orderDate = (
SELECT MAX(orderDate)
FROM orders
);

SELECT o.orderNumber, SUM(od.priceEach * od.quantityOrdered) AS totalValue
FROM orders o
INNER JOIN orderdetails od ON o.orderNumber = od.orderNumber
GROUP BY o.orderNumber;

SELECT c.customerNumber, c.customerName,
SUM(od.priceEach * od.quantityOrdered) AS totalAmountOrdered,
SUM(p.amount) AS totalAmountPaid
FROM customers c
LEFT JOIN orders o ON c.customerNumber = o.customerNumber
LEFT JOIN orderdetails od ON o.orderNumber = od.orderNumber
LEFT JOIN payments p ON o.customerNumber = p.customerNumber
GROUP BY c.customerNumber, c.customerName;