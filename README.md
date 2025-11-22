📘 Electricity Bill Management System (C Project)

A simple Electricity Bill Generator built using C language and file handling.
This project performs customer billing operations, stores user data, calculates charges based on units consumed, and maintains records permanently in files.

⚡ Features (Slide-style Overview)
🧍‍♂️ Customer Management

Add new customer

Search customer bill

Update units

Delete customer record

💡 Billing System

Slab-based billing

Automatic bill calculation

View all bills

📁 File Handling

Data saved permanently (no external database)

Works completely offline

Uses fopen, fread, fwrite and standard file operations

🔢 Billing Slab Rates
Units Consumed	Rate / Unit
0 – 100	₹5
101 – 300	₹7
300+	₹10

Total bill is calculated using the slab into which the units fall.

🛠 Technologies Used

C Language

File Handling

Structures

Functions

Conditional Logic (if-else, switch)

🗂 Project Structure
ebill-c-project/
│
├── ARINDAM.c      // Main project source file
└── README.md      // Project documentation

📥 How to Run the Project
Step 1: Download the C file
ARINDAM.c

Step 2: Compile the program (using GCC)
gcc ARINDAM.c -o bill

Step 3: Run the program
./bill

🖥️ Sample Output
Enter Customer ID: 101
Enter Customer Name: Arindam
Enter Units: 250

Bill Amount: ₹1450
Record Saved Successfully!

📸 Sample Feature Flow (Text-based)
➕ Add Customer
Enter Customer ID: 1
Enter Customer Name: Raja
Enter Units: 180
Customer Added Successfully!

🔍 Search Customer
Enter ID to Search: 1
ID: 1
Name: Raja
Units: 180
Amount: ₹1160

🧑‍💻 Author
Arindam Sahoo
