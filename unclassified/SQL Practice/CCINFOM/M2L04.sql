USE dbsales;
-- Generate a report showing the customers (customer
-- number and complete name), the country they are
-- located and the complete name of the sales
-- representative handling her/him.

SELECT c.customerNumber, c.customerName, 
c.country, 
e.lastName, e.firstName
FROM customers c
JOIN employees e
ON c.salesRepEmployeeNumber = employeeNumber;

-- Generate the list of orders completed in May 2005
-- showing the order number, the order and shipped
-- date and the complete name of the customer that
-- made the order.

SELECT o.orderNumber, o.orderDate,
o.shippedDate, c.customerName 
FROM orders o
JOIN customers c
ON c.customerNumber = o.customerNumber
WHERE o.shippedDate 
BETWEEN '2005-05-01' AND '2005-05-31';

-- Generate the list of products below 300 pieces. Show
-- in the list the product’s code and name, and the
-- product line the product belongs to

SELECT productCode, productName,
productLine
FROM products
WHERE quantityInStock < 300;

-- Generate the complete directory of employees,
-- showing their complete name, email, extension
-- number, the office code they belong to as well as the
-- office phone number.

SELECT e.lastName, e.firstName, e.email,
e.extension, e.officeCode, o.phone
FROM employees e
JOIN offices o
ON e.officeCode = o.officeCode;
