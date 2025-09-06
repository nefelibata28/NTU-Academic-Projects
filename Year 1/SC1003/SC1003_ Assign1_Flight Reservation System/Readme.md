# SC1003 Assignment 1: Flight Seating Reservation System

## Overview
This project implements a **console-based flight seating reservation system** in C for Airlines.  
The airline operates a single plane with **5 seats**, and this system allows passengers to book, cancel, and view reservations.  

The program demonstrates fundamental **C programming concepts** such as structures, arrays, and functions while simulating a simple seat booking workflow.

---

## Features
- **Assign Seat**
  - User enters a seat number (1–5) and passenger name.
  - Prevents double booking by checking seat status.
  - Handles invalid seat numbers and full capacity conditions.
- **List Taken Seats**
  - Displays all reserved seats with customer names and seat IDs.
  - Shows `"The seat assignment list is empty"` if no seats are booked.
- **Remove Seat**
  - User enters a seat number to cancel a booking.
  - Handles invalid input, empty seats, and completely vacant planes.
- **Exit Program**
  - Ends the session gracefully when the user chooses to quit.

---

## Menu
When executed, the program displays the following menu: <br>
NTU AIRLINES SEATING RESERVATION PROGRAM:<br>
1: listTakenSeat() <br>
2: assignSeat() <br>
3: removeSeat() <br>
4: quit <br>

## Technical Details
- **Language:** C  
- **IDE:** Eclipse CDT (C/C++ Development Tooling)  
- **Compiler:** GCC 
