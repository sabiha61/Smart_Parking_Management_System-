# Smart Parking Management System

## 🎯 Project Idea

The **Smart Parking Management System** is a comprehensive console-based application designed to solve the modern-day parking management challenges. The system provides an efficient, automated solution for managing parking slots, facilitating seamless interaction between garage owners, administrators, and end users. 

**Core Concept**: The system acts as a centralized platform where:
- **Garage Owners** can register their parking spaces and make them available for booking
- **Administrators** oversee and approve parking slots, ensuring quality and compliance
- **Users** can easily search, find, and book parking slots based on their location and vehicle type

This system eliminates the traditional manual parking management hassles by automating slot allocation, approval workflows, and booking processes while maintaining data persistence across sessions.

---

## ✨ Key Features

### 🔐 Authentication & User Management
- **Secure Registration System**: Users can register with unique usernames (prevents duplicates)
- **Role-Based Access Control**: Three distinct roles - Admin, Owner, and User
- **File-Based Authentication**: User credentials stored securely in `users.txt`
- **Login Validation**: Credentials verified before granting access to role-specific panels

### 🏢 Garage Owner Features
- **Slot Registration**: Owners can add parking slots with complete details
- **Unique Slot ID Generation**: Automatic sequential ID assignment for each slot
- **Vehicle Type Specification**: Define slot compatibility (Car, Bike, Truck, or Any)
- **Slot Status Tracking**: View all slots with their approval and availability status
- **Pending Approval System**: New slots require admin approval before becoming available

### 👨‍💼 Admin Features
- **Slot Approval Workflow**: Review and approve/reject pending parking slots
- **Comprehensive Slot Management**: View all slots with detailed information
- **Maintenance Control**: Set slots to maintenance mode when needed
- **Status Monitoring**: Track slot availability, booking status, and approval state

### 👤 User Features
- **Available Slot Browsing**: View all approved and available parking slots
- **Location-Based Search**: Find nearby parking slots by entering location keywords
- **Vehicle Type Compatibility**: System ensures bookings match vehicle type requirements
- **Booking System**: Reserve parking slots for specified hours
- **Automatic Receipt Generation**: Get detailed receipts with pricing information

### 🚗 Advanced Booking Features
- **Vehicle-Type Compatibility Check**: Prevents booking mismatches (e.g., can't book a Car slot with a Bike)
- **Real-Time Availability**: Only shows slots that are available and not under maintenance
- **Hour-Based Booking**: Book slots for specific time durations
- **Automatic Price Calculation**: System calculates total cost based on hours and rate

### 📊 Slot Management Features
- **Multi-Status System**: 
  - `Available` (0): Ready for booking
  - `Booked` (1): Currently reserved
  - `Maintenance` (2): Under repair/maintenance
  - `Inactive` (3): Auto-deactivated due to inactivity
- **Auto-Deactivation**: Slots unused for 30+ days automatically become inactive
- **Last Used Tracking**: Monitors days since last booking for each slot
- **Availability Hours**: Tracks remaining bookable hours per slot

### 💾 Data Persistence
- **Automatic Data Saving**: All changes saved to files immediately
- **Backward Compatibility**: System can load old data format and upgrade automatically
- **Multiple Data Files**:
  - `users.txt`: User credentials and roles
  - `slots.txt`: Complete slot information
  - `receipt.txt`: Generated booking receipts
  - `smart_parking_data.txt`: System logs

---

## 🏗️ System Architecture

### Module Structure

#### **Core Modules**
- **`main.c`**: Entry point, main menu, and program flow control
- **`data.c/h`**: Central data structures, file I/O operations, and slot deactivation logic

#### **Authentication Module**
- **`auth1.c/h`**: User registration and login functionality
  - `registerUser()`: Creates new user accounts with duplicate checking
  - `loginUser()`: Validates credentials and returns user role

#### **Admin Module**
- **`admin1.c/h`**: Administrative functions
  - Slot approval workflow
  - Complete slot overview
  - Maintenance status management

#### **Owner Module**
- **`owner1.c/h`**: Garage owner operations
  - Add new parking slots
  - View owned slots with status
  - Unique ID generation

#### **User Module**
- **`user1.c/h`**: End-user functionality
  - Browse available slots
  - Location-based search
  - Booking interface

#### **Booking Module**
- **`booking1.c/h`**: Booking system
  - Vehicle type compatibility validation
  - Status checking (maintenance/inactive)
  - Slot reservation logic

#### **Confirmation Module**
- **`confirmation1.c/h`**: Receipt generation
  - Calculate total cost
  - Generate formatted receipts
  - Save receipts to file

#### **Utility Modules**
- **`slot1.c/h`**: Slot status display functions
- **`logs1.c/h`**: System logging functionality
- **`fraud1.c/h`**: Fraud detection framework (extensible)

---

## 📋 Data Structures

### Slot Structure
```c
typedef struct {
    int id;                 // Unique slot identifier
    char location[50];      // Parking location
    int pricePerHour;      // Pricing rate
    int availableHours;     // Remaining bookable hours
    int isApproved;         // Admin approval status (0=pending, 1=approved)
    char bookedBy[50];      // Current booking user
    int lastBookedHours;    // Hours in current booking
    int startTime;          // Slot operating start time
    int endTime;            // Slot operating end time
    char vehicleType[20];   // Compatible vehicle type
    int status;             // Current status (0=Available, 1=Booked, 2=Maintenance, 3=Inactive)
    int lastUsedDate;       // Days since last booking
} Slot;
```

---

## 🚀 Getting Started

### Prerequisites
- **GCC Compiler** (MinGW-w64 on Windows, gcc on Linux/Mac)
- **Code::Blocks IDE** (optional, for easier development)

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/sabiha61/Smart_Parking_Management_System-.git
   cd Smart_Parking_Management_System-
   ```

2. **Compile the project**

   **Using Code::Blocks:**
   - Open `Smart-Parking.cbp`
   - Press **F9** to Build
   - Press **F10** to Run

   **Using Command Line:**
   ```bash
   gcc -o Smart-Parking main.c data.c admin1.c owner1.c user1.c booking1.c confirmation1.c auth1.c
   ./Smart-Parking    # Linux/Mac
   Smart-Parking.exe  # Windows
   ```

---

## 📖 Usage Guide

### Workflow

1. **Registration**
   - Choose option 1 from main menu
   - Enter username, password, and role (Admin/Owner/User)
   - System validates username uniqueness

2. **Login**
   - Choose option 2 from main menu
   - Enter credentials
   - Access role-specific dashboard

3. **Owner Workflow**
   - Add parking slots with details (location, price, hours, vehicle type)
   - Slots are created in "Pending" status
   - View all your slots and their approval status

4. **Admin Workflow**
   - Review pending slots
   - Approve or reject slots
   - Set maintenance status when needed
   - Monitor all slots in the system

5. **User Workflow**
   - Browse available slots
   - Search by location
   - Book slots matching your vehicle type
   - Receive automatic receipts

### Example Session

```
===== SMART PARKING MANAGEMENT SYSTEM =====
1. Register
2. Login
3. Exit
Choice: 1

Enter Username: john_owner
Enter Password: pass123
Enter Role (Admin/Owner/User): Owner
Registration Successful!

[After login as Owner]
===== OWNER PANEL =====
1. Add Parking Slot
2. View Slots
3. Logout
Choice: 1

Enter location: Downtown_Mall
Enter price per hour: 50
Enter available hours: 24
Enter start time (hour): 8
Enter end time (hour): 22
Enter vehicle type (Car/Bike/Truck/Any): Car
Slot added successfully. Pending admin approval.
```

---

## 🔧 Technical Details

### File I/O Operations
- **Read Operations**: Load slots and users on program startup
- **Write Operations**: Save data immediately after modifications
- **Format Compatibility**: Supports both old and new data formats

### Slot Deactivation Logic
- Runs automatically on program startup
- Increments `lastUsedDate` for available slots
- Deactivates slots with `lastUsedDate > 30` days
- Resets counter when slot is booked

### Vehicle Type Matching
- Exact match required (case-sensitive)
- "Any" type accepts all vehicles
- Prevents incompatible bookings

### Location Search Algorithm
- Substring matching (case-sensitive)
- Bidirectional search (slot location contains search term or vice versa)
- Shows all matching available slots

---

## 📁 Project Files

### Source Files (Core)
- `main.c` - Main program entry
- `data.c/h` - Data management
- `auth1.c/h` - Authentication
- `admin1.c/h` - Admin functions
- `owner1.c/h` - Owner functions
- `user1.c/h` - User functions
- `booking1.c/h` - Booking system
- `confirmation1.c/h` - Receipt generation

### Additional Modules
- `slot1.c/h` - Slot utilities
- `logs1.c/h` - Logging system
- `fraud1.c/h` - Fraud detection
- `report1.c/h`, `report2.c/h` - Reporting modules
- `utils1.c/h`, `utils2.c/h` - Utility functions

### Data Files
- `users.txt` - User database
- `slots.txt` - Slot database
- `receipt.txt` - Latest booking receipt
- `smart_parking_data.txt` - System logs

### Project Configuration
- `Smart-Parking.cbp` - Code::Blocks project file
- `Smart-Parking.depend` - Dependency tracking
