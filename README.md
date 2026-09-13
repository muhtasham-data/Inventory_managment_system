# Inventory Management System

A CLI inventory management system written in C++17. Built to handle store stock tracking, product lookups, transactions, and CSV file persistence.

The main focus of this project was designing a scalable OOP structure while avoiding common C++ memory issues—specifically preventing instance duplication during database access and resolving circular header dependencies.

## Features

- Add, update, search, and delete products
- Process sales and restock inventory with quantity checks
- Low-stock detection warnings
- Input validation to handle non-numeric inputs without infinite loop crashes
