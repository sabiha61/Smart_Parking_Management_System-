# Your Features - Files to Understand

## 📁 Feature 6: Garage Owner Registration

### **Files to Study:**

1. **`auth1.c`** - Core authentication logic
   - `registerUser()` - Checks for duplicate usernames, saves to file
   - `loginUser()` - Validates credentials, returns user role
   - File: `users.txt` - Stores user data

2. **`auth1.h`** - Function declarations
   - Function signatures for registration and login

3. **`main.c`** (lines 23-34, 36-52) - Integration
   - Registration menu option calls `registerUser()`
   - Login menu option calls `loginUser()`
   - Role-based menu routing after login

**Key Code Sections:**
- `main.c` line 29: `if(registerUser(username, password, role))`
- `main.c` line 42: `if(loginUser(username, password, roleOut))`
- `auth1.c` line 8-24: Registration function
- `auth1.c` line 26-40: Login function

---

## 🚗 Feature 8: Vehicle-Type Compatibility Check

### **Files to Study:**

1. **`data.h`** (line 16) - Data structure
   - `char vehicleType[20]` - Field added to Slot structure

2. **`owner1.c`** (line 26) - Input collection
   - Owner specifies vehicle type when creating slot
   - `scanf("%s",s.vehicleType)` - Gets vehicle type

3. **`booking1.c`** (lines 11-17) - Validation logic
   - Checks if vehicle type matches before booking
   - Prevents incompatible bookings

4. **`booking1.h`** - Function signature
   - `void bookSlot1(int slotId, int hours, char* vehicleType)`

5. **`user1.c`** (line 57) - User input
   - User enters their vehicle type when booking

**Key Code Sections:**
- `data.h` line 16: `char vehicleType[20]` - Field definition
- `owner1.c` line 26: Vehicle type input
- `booking1.c` lines 12-17: Compatibility check
- `user1.c` line 57: User vehicle type input

---

## 🔧 Feature 9: Slot Availability Control

### **Files to Study:**

1. **`data.h`** (line 17) - Status field
   - `int status` - 0=Available, 1=Booked, 2=Maintenance, 3=Inactive

2. **`owner1.c`** (line 28, 39-43) - Status initialization and display
   - Sets status to 0 (Available) when creating slot
   - Displays status in slot list

3. **`admin1.c`** (lines 30-34, 47-66) - Maintenance control
   - Displays status for all slots
   - Option 3: Set maintenance status
   - Can change status between Available and Maintenance

4. **`booking1.c`** (lines 19-27, 32) - Status validation
   - Checks if slot is in maintenance before booking
   - Sets status to 1 (Booked) when booking succeeds

5. **`user1.c`** (line 18) - Status filtering
   - Only shows slots with status 0 (Available)

**Key Code Sections:**
- `data.h` line 17: `int status` - Status field definition
- `owner1.c` line 28: `s.status = 0` - Initialize as Available
- `admin1.c` lines 47-66: Maintenance status setting
- `booking1.c` lines 20-27: Status validation before booking
- `booking1.c` line 32: `slots[i].status = 1` - Set to Booked

---

## ⏰ Feature 10: Slot Deactivation System

### **Files to Study:**

1. **`data.h`** (line 18, 26) - Field and function declaration
   - `int lastUsedDate` - Tracks days since last use
   - `void checkSlotDeactivation()` - Function declaration

2. **`data.c`** (lines 73-88) - Deactivation logic
   - `checkSlotDeactivation()` function
   - Increments `lastUsedDate` for available slots
   - Auto-deactivates slots unused for 30+ days

3. **`main.c`** (line 65) - Function call
   - Calls `checkSlotDeactivation()` on program startup

4. **`booking1.c`** (line 33) - Reset counter
   - Resets `lastUsedDate = 0` when slot is booked

**Key Code Sections:**
- `data.h` line 18: `int lastUsedDate` - Field definition
- `data.c` lines 73-88: Complete deactivation function
- `data.c` line 77: Increment counter for unused slots
- `data.c` line 82: Deactivation condition (30+ days)
- `main.c` line 65: Startup check
- `booking1.c` line 33: Reset on booking

---

## 🔍 Feature 11: Location-Based Slot Search

### **Files to Study:**

1. **`user1.c`** (lines 29-52) - Complete search implementation
   - Option 2 in user menu
   - Location input
   - Search algorithm using `strstr()`
   - Results display

**Key Code Sections:**
- `user1.c` line 12: Menu option added
- `user1.c` line 32: Location input
- `user1.c` lines 38-39: Search algorithm (substring matching)
- `user1.c` lines 40-46: Display matching slots
- `user1.c` line 51: "No slots found" message

---

## 📊 Summary Table

| Feature | Primary Files | Key Functions/Lines |
|---------|--------------|---------------------|
| **Feature 6** | `auth1.c`, `auth1.h`, `main.c` | `registerUser()`, `loginUser()`, main menu integration |
| **Feature 8** | `data.h`, `booking1.c`, `owner1.c`, `user1.c` | `vehicleType` field, compatibility check in `bookSlot1()` |
| **Feature 9** | `data.h`, `admin1.c`, `owner1.c`, `booking1.c` | `status` field, maintenance control, status validation |
| **Feature 10** | `data.h`, `data.c`, `main.c`, `booking1.c` | `lastUsedDate` field, `checkSlotDeactivation()` |
| **Feature 11** | `user1.c` | Location search in `userMenu()` option 2 |

---

## 🎯 Quick Study Guide

### **Start Here (Core Understanding):**
1. **`data.h`** - Understand the Slot structure (all new fields)
2. **`data.c`** - Understand save/load and deactivation logic

### **Then Study Feature-Specific Files:**
3. **Feature 6**: `auth1.c` → `main.c` (integration)
4. **Feature 8**: `owner1.c` (input) → `booking1.c` (validation)
5. **Feature 9**: `admin1.c` (maintenance) → `booking1.c` (status check)
6. **Feature 10**: `data.c` (deactivation function)
7. **Feature 11**: `user1.c` (search function)

---

## 💡 Key Concepts to Understand

### **For Feature 6 (Registration):**
- File I/O operations (`fopen`, `fscanf`, `fprintf`)
- Duplicate checking algorithm
- String comparison (`strcmp`)

### **For Feature 8 (Vehicle Compatibility):**
- String comparison for validation
- Function parameter passing (`char* vehicleType`)
- Conditional logic for type matching

### **For Feature 9 (Status Control):**
- Integer status codes (0, 1, 2, 3)
- Status display with string conversion
- Admin control over slot status

### **For Feature 10 (Deactivation):**
- Counter increment logic
- Conditional deactivation (30+ days)
- Automatic execution on startup

### **For Feature 11 (Location Search):**
- String search using `strstr()`
- Bidirectional substring matching
- Filtering and display logic

---

## 🔑 Most Important Files for Your Presentation

**Must Understand:**
1. `data.h` - All new fields (vehicleType, status, lastUsedDate)
2. `booking1.c` - Vehicle compatibility + status validation
3. `user1.c` - Location search implementation
4. `admin1.c` - Maintenance control
5. `data.c` - Deactivation logic

**Supporting Files:**
- `auth1.c` - Registration system
- `owner1.c` - Slot creation with vehicle type
- `main.c` - Integration points

---

**Focus on these files to explain your features clearly! 🎓**

