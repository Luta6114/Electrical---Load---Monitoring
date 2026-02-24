# Electrical Load Monitoring System

## Overview

The Electrical Load Monitoring System is a simple C++ console-based application used to monitor and calculate the daily energy consumption of household appliances. It allows users to register appliances, compute total energy usage in kWh per day, and estimate electricity costs based on a given tariff.

This project was developed as a basic programming exercise using standard C++ features such as structures, vectors, file handling, and input validation.

---

## Features

- Register new appliances  
- View all registered appliances  
- Search appliances by name (case-insensitive)  
- Display total daily energy consumption (kWh/day)  
- Calculate estimated electricity bill  
- Save appliance records to a file  
- Save billing summaries to a file  

---

## How It Works

For each appliance, the user provides:

- Appliance name  
- Power rating (in Watts)  
- Usage hours per day  

The program calculates daily energy consumption using the formula:

Energy (kWh/day) = (Power in Watts × Hours per Day) / 1000  

To estimate the electricity bill:

Total Cost = Total Energy (kWh/day) × Tariff per kWh  

All calculations are displayed in the console, and billing results are saved for record keeping.

---

## Files Generated

When the program runs, the following files are automatically created:

- appliances.txt  
  Stores registered appliance information including name, power rating, usage hours, and daily energy consumption.

- billing_summary.txt  
  Stores billing calculation results including total energy, tariff, and total cost.

---

## Program Menu

The system provides the following menu options:

1. Register appliance  
2. View all appliances  
3. Search appliance by name  
4. Energy summary (kWh/day)  
5. Billing summary  
0. Exit  

---

## Compilation and Execution

To compile and run the program using g++:

g++ main.cpp -o load_monitor  
./load_monitor  

(Replace `main.cpp` with your actual source file name if different.)

---

## Requirements

- C++ compiler (C++11 or later recommended)  
- Terminal or command prompt environment  

---

## Purpose

This project demonstrates:

- Use of structures (`struct`)  
- Vector data storage  
- Input validation  
- File handling (`fstream`)  
- Basic mathematical calculations  
- Menu-driven program design  

---

## Author

Developed as a C++ learning project.