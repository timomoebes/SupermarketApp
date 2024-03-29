# Supermarket Shopping System

This repository contains a C++ application for managing a simple supermarket shopping system. It is designed as a console application to demonstrate basic concepts of object-oriented programming, file handling, and user interaction in C++.

## Features

- **Administrator and Buyer Modes**: Separate functionalities for administrators and buyers.
- **Product Management**: Administrators can add, edit, and delete products.
- **Shopping Cart**: Buyers can select products and quantities, view their receipt with total amount including discounts.
- **File Handling**: Product data is stored and retrieved from a text file (`database.txt`), demonstrating basic file operations.

## Getting Started

To run this project on your local machine, follow these steps:

### Prerequisites

Ensure you have a C++ compiler installed on your system. GCC/G++ or Clang are recommended. This project was developed with standard C++11, so it should be compatible with most compilers.

### Installation

1. Clone the repository to your local machine:
git clone https://github.com/timomoebes/SupermarketApp.git

2. Navigate to the cloned directory.
3. Compile the C++ file. For example, if you are using G++, run:
   g++ -std=c++11 -o billing1 billing1.cpp

4. Run the compiled application:
   ./billing1

## Usage

Upon running the application, you will be greeted with the main menu. You can choose to enter as an administrator or a buyer:

- **Administrator Mode**: Log in with the correct credentials. Once logged in, you can add, edit, or delete products in the system.
- **Buyer Mode**: Browse available products and add them to your shopping cart. Once you are done, you can view your receipt.

## License

Distributed under the MIT License. See `LICENSE` for more information.
