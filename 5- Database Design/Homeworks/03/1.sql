CREATE TABLE Customers
(
    CustomerID   NUMERIC,
    CustomerName VARCHAR(32),
    ContactName  VARCHAR(32),
    Country      VARCHAR(32),
    PRIMARY KEY (CustomerID)
);

CREATE TABLE Orders
(
    OrderID     NUMERIC,
    CustomerID  NUMERIC,
    OrderDate   DATE,
    ShipCity    VARCHAR(32),
    ShipCountry VARCHAR(32),
    PRIMARY KEY (OrderID),
    FOREIGN KEY (CustomerID) REFERENCES Customers (CustomerID)
);

CREATE TABLE OrderDetails
(
    OrderDetailID NUMERIC,
    OrderID       NUMERIC,
    ProductID     NUMERIC,
    Quantity      NUMERIC,
    PRIMARY KEY (OrderDetailID),
    FOREIGN KEY (OrderID) REFERENCES Orders (OrderID),
    FOREIGN KEY (ProductID) REFERENCES Products (ProductID)
);

CREATE TABLE Products
(
    ProductID   NUMERIC,
    ProductName VARCHAR(32),
    SupplierID  NUMERIC,
    CategoryID  NUMERIC,
    UnitPrice   NUMERIC,
    PRIMARY KEY (ProductID),
    FOREIGN KEY (SupplierID) REFERENCES Suppliers (SupplierID),
    FOREIGN KEY (CategoryID) REFERENCES Categories (CategoryID)
);

CREATE TABLE Suppliers
(
    SupplierID   NUMERIC,
    SupplierName VARCHAR(32),
    ContactName  VARCHAR(32),
    Country      VARCHAR(32),
    PRIMARY KEY (SupplierID)
);

CREATE TABLE Categories
(
    CategoryID   NUMERIC,
    CategoryName VARCHAR(32),
    Description  VARCHAR(256),
    PRIMARY KEY (CategoryID)
);

CREATE TABLE Employees
(
    EmployeeID NUMERIC,
    LastName   VARCHAR(32),
    FirstName  VARCHAR(32),
    BirthDate  DATE,
    Photo      BINARY,
    Notes      VARCHAR(512),
    PRIMARY KEY (EmployeeID)
);

CREATE TABLE Territories
(
    TerritoryID   NUMERIC,
    TerritoryName VARCHAR(32),
    RegionID      NUMERIC,
    PRIMARY KEY (TerritoryID),
    FOREIGN KEY (RegionID) REFERENCES Regions (RegionID)
);

CREATE TABLE EmployeeTerritories
(
    EmployeeID  NUMERIC,
    TerritoryID NUMERIC,
    PRIMARY KEY (EmployeeID),
    FOREIGN KEY (EmployeeID) REFERENCES Employees (EmployeeID),
    FOREIGN KEY (TerritoryID) REFERENCES Territories (TerritoryID)
);

CREATE TABLE Regions
(
    RegionID   NUMERIC,
    RegionName VARCHAR(32),
    PRIMARY KEY (RegionID)
);


INSERT INTO Regions(RegionID, RegionName) VALUE (1, 'ASIA');
INSERT INTO Regions(RegionID, RegionName) VALUE (2, 'EUROPE');
INSERT INTO Regions(RegionID, RegionName) VALUE (3, 'AFRICA');
INSERT INTO Regions(RegionID, RegionName) VALUE (4, 'NORTH AMERICA');
INSERT INTO Regions(RegionID, RegionName) VALUE (5, 'SOUTH AMERICA');

INSERT INTO territories(TerritoryID, TerritoryName, RegionID) VALUE (1, 'JAPAN', 1);
INSERT INTO territories(TerritoryID, TerritoryName, RegionID) VALUE (2, 'GERMANY', 2);
INSERT INTO territories(TerritoryID, TerritoryName, RegionID) VALUE (3, 'EGYPT', 3);
INSERT INTO territories(TerritoryID, TerritoryName, RegionID) VALUE (4, 'CANADA', 4);
INSERT INTO territories(TerritoryID, TerritoryName, RegionID) VALUE (5, 'ARGENTINA', 5);

INSERT INTO employees(EmployeeID, LastName, FirstName, BirthDate, Photo, Notes) VALUE (1, 'SKYWALKER', 'ANAKIN', '2001-01-01', 0x0001, 'one');
INSERT INTO employees(EmployeeID, LastName, FirstName, BirthDate, Photo, Notes) VALUE (2, 'ARLERT', 'ARMIN', '2002-02-02', 0x0010, 'two');
INSERT INTO employees(EmployeeID, LastName, FirstName, BirthDate, Photo, Notes) VALUE (3, 'ALLEN', 'BARRY', '2003-03-03', 0x0011, 'three');
INSERT INTO employees(EmployeeID, LastName, FirstName, BirthDate, Photo, Notes) VALUE (4, 'PARKER', 'PETER', '2004-04-04', 0x0100, 'four');
INSERT INTO employees(EmployeeID, LastName, FirstName, BirthDate, Photo, Notes) VALUE (5, 'YAGAMI', 'LIGHT', '2005-05-05', 0x0101, 'five');

INSERT INTO employeeterritories(EmployeeID, TerritoryID) VALUE (1,1);
INSERT INTO employeeterritories(EmployeeID, TerritoryID) VALUE (2,2);
INSERT INTO employeeterritories(EmployeeID, TerritoryID) VALUE (3,3);
INSERT INTO employeeterritories(EmployeeID, TerritoryID) VALUE (4,4);
INSERT INTO employeeterritories(EmployeeID, TerritoryID) VALUE (5,5);

INSERT INTO customers (CustomerID, CustomerName, ContactName, Country) VALUE (1, 'ONE', 'C1', 'KENYA');
INSERT INTO customers (CustomerID, CustomerName, ContactName, Country) VALUE (2, 'TWO', 'C2', 'ZIMBABWE');
INSERT INTO customers (CustomerID, CustomerName, ContactName, Country) VALUE (3, 'THREE', 'C3', 'NIGER');
INSERT INTO customers (CustomerID, CustomerName, ContactName, Country) VALUE (4, 'FOUR', 'C4', 'GUINEA-BISSAU');
INSERT INTO customers (CustomerID, CustomerName, ContactName, Country) VALUE (5, 'FIVE', 'C5', 'MADAGASCAR');

INSERT INTO suppliers(SupplierID, SupplierName, ContactName, Country) VALUE (1, 'YEK', 'S1', 'BRAZIL');
INSERT INTO suppliers(SupplierID, SupplierName, ContactName, Country) VALUE (2, 'DO', 'S2', 'ARGENTINA');
INSERT INTO suppliers(SupplierID, SupplierName, ContactName, Country) VALUE (3, 'SE', 'S3', 'CHILE');
INSERT INTO suppliers(SupplierID, SupplierName, ContactName, Country) VALUE (4, 'CHAR', 'S4', 'URUGUAY');
INSERT INTO suppliers(SupplierID, SupplierName, ContactName, Country) VALUE (5, 'PANJ', 'S5', 'COLOMBIA');

INSERT INTO categories(CategoryID, CategoryName, Description) VALUE (1, 'Ct1', '...');
INSERT INTO categories(CategoryID, CategoryName, Description) VALUE (2, 'Ct2', '...');
INSERT INTO categories(CategoryID, CategoryName, Description) VALUE (3, 'Ct3', '...');
INSERT INTO categories(CategoryID, CategoryName, Description) VALUE (4, 'Ct4', '...');
INSERT INTO categories(CategoryID, CategoryName, Description) VALUE (5, 'Ct5', '...');

INSERT INTO orders(OrderID, CustomerID, OrderDate, ShipCity, ShipCountry) VALUE (1, 1, '2001-01-01', 'SAN FRANCISCO', 'USA');
INSERT INTO orders(OrderID, CustomerID, OrderDate, ShipCity, ShipCountry) VALUE (2, 2, '2002-02-02', 'TOKYO', 'JAPAN');
INSERT INTO orders(OrderID, CustomerID, OrderDate, ShipCity, ShipCountry) VALUE (3, 3, '2003-03-03', 'BERLIN', 'GERMANY');
INSERT INTO orders(OrderID, CustomerID, OrderDate, ShipCity, ShipCountry) VALUE (4, 4, '2004-04-04', 'VANCOUVER', 'CANADA');
INSERT INTO orders(OrderID, CustomerID, OrderDate, ShipCity, ShipCountry) VALUE (5, 1, '2005-05-05', 'TEHRAN', 'IRAN');

INSERT INTO products(ProductID, ProductName, SupplierID, CategoryID, UnitPrice) VALUE (1, 'P1', 1, 1, 1000);
INSERT INTO products(ProductID, ProductName, SupplierID, CategoryID, UnitPrice) VALUE (2, 'P2', 2, 2, 2000);
INSERT INTO products(ProductID, ProductName, SupplierID, CategoryID, UnitPrice) VALUE (3, 'P3', 3, 3, 3000);
INSERT INTO products(ProductID, ProductName, SupplierID, CategoryID, UnitPrice) VALUE (4, 'P4', 4, 4, 4000);
INSERT INTO products(ProductID, ProductName, SupplierID, CategoryID, UnitPrice) VALUE (5, 'P5', 5, 5, 5000);

INSERT INTO orderdetails(OrderDetailID, OrderID, ProductID, Quantity) VALUE (1, 1, 1, 100);
INSERT INTO orderdetails(OrderDetailID, OrderID, ProductID, Quantity) VALUE (2, 2, 2, 200);
INSERT INTO orderdetails(OrderDetailID, OrderID, ProductID, Quantity) VALUE (3, 3, 3, 300);
INSERT INTO orderdetails(OrderDetailID, OrderID, ProductID, Quantity) VALUE (4, 4, 4, 400);
INSERT INTO orderdetails(OrderDetailID, OrderID, ProductID, Quantity) VALUE (5, 5, 1, 500);


-- Query 1
SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate 
FROM Orders
    INNER JOIN Customers ON Orders.CustomerID = Customers.CustomerID;

-- Query 2
SELECT
    Orders.OrderID, Products.ProductName, Products.UnitPrice, OrderDetails.Quantity,
    SUM(OrderDetails.Quantity * Products.UnitPrice) AS TotalAmount
FROM Orders
    INNER JOIN OrderDetails ON Orders.OrderID = OrderDetails.OrderID
    INNER JOIN Products ON OrderDetails.ProductID = Products.ProductID;

-- Query 3
SELECT Customers.CustomerName, COUNT(Orders.OrderID) AS NumOrders
FROM Customers
    INNER JOIN Orders ON Customers.CustomerID = Orders.CustomerID
GROUP BY Customers.CustomerName
ORDER BY NumOrders DESC LIMIT 5;

-- Query 4 
SELECT Products.*, Categories.CategoryName, Suppliers.SupplierName
FROM Products
    INNER JOIN Categories ON Products.CategoryID = Categories.CategoryID
    INNER JOIN Suppliers ON Products.SupplierID = Suppliers.SupplierID;

-- Query 5
SELECT products.ProductID, products.ProductName, SUM(orderdetails.Quantity), suppliers.SupplierID 
FROM products 
    INNER JOIN orderdetails ON orderdetails.ProductID=products.ProductID 
    INNER JOIN suppliers ON suppliers.SupplierID=products.SupplierID
GROUP BY suppliers.SupplierID;

-- Query 6
SELECT products.ProductID, products.ProductName, SUM(orderdetails.Quantity * products.UnitPrice),
    SUM(orderdetails.Quantity), categories.CategoryID, AVG(products.UnitPrice)
FROM products 
    INNER JOIN orderdetails ON orderdetails.ProductID=products.ProductID 
    INNER JOIN categories ON categories.CategoryID=products.SupplierID
GROUP BY categories.CategoryID;

-- Query 7
SELECT employees.EmployeeID, regions.RegionID
FROM employees
    INNER JOIN employeeterritories ON employeeterritories.EmployeeID=employees.EmployeeID
    INNER JOIN regions ON regions.RegionID=employeeterritories.TerritoryID;

-- Query 8
SELECT orders.ShipCity, COUNT(orders.OrderID) AS OrderCount
FROM orders
GROUP BY orders.ShipCity
ORDER BY OrderCount ASC;

-- Query 9
SELECT products.*
FROM products
    WHERE NOT EXISTS (SELECT orderdetails.ProductID FROM orderdetails WHERE orderdetails.ProductID=products.ProductID);

-- Query 10
SELECT customers.CustomerID, COUNT(customers.CustomerID) AS CustomerOrderCount
FROM customers
    INNER JOIN orders ON orders.CustomerID=customers.CustomerID
GROUP BY customers.CustomerID
HAVING CustomerOrderCount > 3;
