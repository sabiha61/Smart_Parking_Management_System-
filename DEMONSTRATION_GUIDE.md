# Smart Parking Management System - Demonstration Guide

## 🎯 Quick Start

### Step 1: Open in Code::Blocks
1. Open Code::Blocks
2. File → Open → Select `Smart-Parking.cbp`
3. Press **F9** to Build
4. Press **F10** to Run

---

## 📋 Complete Feature Demonstration

### **PART 1: Registration & Authentication System**

#### Feature 6: Garage Owner Registration (✅ YOUR FEATURE)

**Demonstration:**
```
===== SMART PARKING MANAGEMENT SYSTEM =====
1. Register
2. Login
3. Exit
Choice: 1

Enter Username: owner1
Enter Password: pass123
Enter Role (Admin/Owner/User): Owner
Registration Successful!
```

**What to Show:**
- ✅ Registration saves to `users.txt` file
- ✅ Duplicate username detection (try registering same username twice)
- ✅ File-based authentication system

**Test Duplicate Prevention:**
```
Choice: 1
Enter Username: owner1  (same username)
Enter Password: pass456
Enter Role (Admin/Owner/User): Owner
Registration Failed! Username may already exist.
```

---

### **PART 2: Owner Features**

#### Feature 7: Unique Slot ID Generator (✅ IMPLEMENTED)

**Demonstration:**
```
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

**What to Show:**
- ✅ Slot ID is auto-generated (SlotCount + 1)
- ✅ Each slot gets unique sequential ID
- ✅ Slot is created in "Pending" status

**Add Multiple Slots:**
```
Slot 1: ID = 1, Location = Downtown_Mall, Vehicle = Car
Slot 2: ID = 2, Location = Airport, Vehicle = Bike
Slot 3: ID = 3, Location = University, Vehicle = Any
```

---

#### Feature 8: Vehicle-Type Compatibility (✅ YOUR FEATURE)

**Demonstration:**
```
===== OWNER PANEL =====
Choice: 1

Enter location: Shopping_Center
Enter price per hour: 40
Enter available hours: 12
Enter start time (hour): 9
Enter end time (hour): 21
Enter vehicle type (Car/Bike/Truck/Any): Bike
Slot added successfully. Pending admin approval.
```

**What to Show:**
- ✅ Owner specifies vehicle type when creating slot
- ✅ Options: Car, Bike, Truck, or Any
- ✅ This will be validated during booking

---

#### Feature 9: Slot Availability Control (✅ YOUR FEATURE)

**View Slots with Status:**
```
===== OWNER PANEL =====
Choice: 2

Your Slots:
ID:1 | Downtown_Mall | Car | 24 hrs | 50 tk/hr | Pending | Available
ID:2 | Airport | Bike | 20 hrs | 30 tk/hr | Approved | Available
ID:3 | University | Any | 18 hrs | 35 tk/hr | Approved | Booked
```

**What to Show:**
- ✅ Status display: Available, Booked, Maintenance, Inactive
- ✅ Shows vehicle type for each slot
- ✅ Shows approval status

---

### **PART 3: Admin Features**

#### Admin Approval System

**Login as Admin:**
```
===== SMART PARKING MANAGEMENT SYSTEM =====
Choice: 2

Username: admin
Password: admin123
Welcome admin!
Role: Admin
```

**Approve Slots:**
```
===== ADMIN PANEL =====
1. Approve Slots
2. View All Slots
3. Set Slot Maintenance (Feature 9)
4. Logout
Choice: 1

Pending Slots:
ID:1 | Downtown_Mall | 24 hrs | 50 tk/hr
Approve this slot? (1=Yes,0=No): 1
```

**What to Show:**
- ✅ Admin reviews pending slots
- ✅ Can approve or reject
- ✅ Approved slots become available for booking

---

#### Feature 9: Maintenance Control (✅ YOUR FEATURE)

**Set Maintenance Status:**
```
===== ADMIN PANEL =====
Choice: 3

Enter Slot ID: 2
Set status - 0=Available, 2=Maintenance: 2
Slot 2 status updated to Maintenance
```

**What to Show:**
- ✅ Admin can set slots to Maintenance mode
- ✅ Maintenance slots cannot be booked
- ✅ Can change back to Available

**View All Slots:**
```
===== ADMIN PANEL =====
Choice: 2

All Slots:
ID:1 | Downtown_Mall | Car | 24 hrs | 50 tk/hr | Approved | Available
ID:2 | Airport | Bike | 20 hrs | 30 tk/hr | Approved | Maintenance
ID:3 | University | Any | 18 hrs | 35 tk/hr | Approved | Booked
```

---

### **PART 4: User Features**

#### Register and Login as User

```
===== SMART PARKING MANAGEMENT SYSTEM =====
Choice: 1

Enter Username: user1
Enter Password: user123
Enter Role (Admin/Owner/User): User
Registration Successful!

[Login]
Username: user1
Password: user123
Welcome user1!
Role: User
```

---

#### Feature 11: Location-Based Search (✅ YOUR FEATURE)

**Search by Location:**
```
===== USER PANEL =====
1. View Available Slots
2. Search Slots by Location (Feature 11)
3. Book Slot
4. Logout
Choice: 2

Enter location to search: Downtown

Slots near 'Downtown':
ID:1 | Downtown_Mall | Car | 24 hrs free | 50 tk/hr
```

**What to Show:**
- ✅ Enter location keyword
- ✅ System finds matching slots
- ✅ Shows only available slots
- ✅ Displays vehicle type compatibility

**Test Different Searches:**
```
Search: "Airport" → Shows Airport slots
Search: "University" → Shows University slots
Search: "Mall" → Shows Downtown_Mall slots
Search: "xyz" → "No slots found near 'xyz'"
```

---

#### View Available Slots

```
===== USER PANEL =====
Choice: 1

Available Slots:
ID:1 | Downtown_Mall | Car | 24 hrs free | 50 tk/hr
ID:3 | University | Any | 18 hrs free | 35 tk/hr
```

**What to Show:**
- ✅ Only shows approved and available slots
- ✅ Shows vehicle type
- ✅ Shows available hours and pricing

---

#### Feature 8: Vehicle-Type Compatibility Check (✅ YOUR FEATURE)

**Book Slot - Correct Vehicle Type:**
```
===== USER PANEL =====
Choice: 3

Enter Slot ID to book: 1
Enter your vehicle type (Car/Bike/Truck): Car
Enter hours to book: 2
Slot booked successfully.

========== PARKING RECEIPT ==========
User        : user1
Location    : Downtown_Mall
Hours Booked: 2
Rate/hour   : 50 TK
------------------------------------
TOTAL       : 100 TK
====================================
```

**What to Show:**
- ✅ Booking successful when vehicle types match
- ✅ Receipt generated automatically
- ✅ Slot status changes to "Booked"
- ✅ Available hours reduced

**Book Slot - Wrong Vehicle Type (ERROR):**
```
Enter Slot ID to book: 1
Enter your vehicle type (Car/Bike/Truck): Bike
Enter hours to book: 2
Error: Vehicle type mismatch! Slot is for Car, but you have Bike.
```

**What to Show:**
- ✅ System prevents incompatible bookings
- ✅ Clear error message
- ✅ Booking fails if types don't match

**Book Slot - Maintenance Status (ERROR):**
```
Enter Slot ID to book: 2
Enter your vehicle type (Car/Bike/Truck): Bike
Enter hours to book: 2
Error: Slot is under maintenance.
```

**What to Show:**
- ✅ Cannot book maintenance slots
- ✅ Cannot book inactive slots
- ✅ Cannot book already booked slots

---

### **PART 5: Feature 10 - Auto Deactivation (✅ YOUR FEATURE)**

**Demonstration:**
1. Close the program
2. Reopen and run it
3. On startup, system checks for unused slots

**What Happens:**
- System increments `lastUsedDate` for available slots
- If a slot hasn't been used for 30+ days, it becomes "Inactive"
- Inactive slots cannot be booked

**To Show This:**
```
[On program startup]
Slot ID 5 auto-deactivated (not used for 31 days)
```

**View Inactive Slots:**
```
===== ADMIN PANEL =====
Choice: 2

All Slots:
...
ID:5 | Old_Location | Car | 10 hrs | 40 tk/hr | Approved | Inactive
```

---

## 🎤 Presentation Script

### **Introduction (30 seconds)**
"Today I'll demonstrate the Smart Parking Management System, a console-based application that manages parking slots with role-based access control. I've implemented several key features including vehicle-type compatibility, location-based search, and automatic slot deactivation."

### **Feature 1: Registration System (1 minute)**
"First, let me show the registration system. Users can register with unique usernames, and the system prevents duplicates. Notice how it saves to a file for persistence."

### **Feature 2: Owner - Add Slots (1 minute)**
"As an owner, I can add parking slots. Each slot gets a unique ID automatically. I specify the location, price, hours, and importantly - the vehicle type. This ensures only compatible vehicles can book."

### **Feature 3: Admin - Approval & Maintenance (1 minute)**
"The admin reviews and approves slots. They can also set slots to maintenance mode when needed. Notice the status tracking - Available, Booked, Maintenance, or Inactive."

### **Feature 4: User - Location Search (1 minute)**
"Users can search for parking by location. This is my location-based search feature. It finds nearby slots matching the search term."

### **Feature 5: Vehicle Compatibility (1 minute)**
"When booking, the system validates vehicle type. If I try to book a Car slot with a Bike, it's rejected. This prevents booking mismatches."

### **Feature 6: Auto Deactivation (30 seconds)**
"Finally, slots unused for 30+ days automatically become inactive, keeping the system clean and up-to-date."

---

## 📊 Feature Summary Table

| Feature | Status | Location | What It Does |
|---------|--------|----------|--------------|
| **Feature 6: Owner Registration** | ✅ Implemented | `auth1.c`, `main.c` | File-based user registration with duplicate checking |
| **Feature 7: Unique Slot ID** | ✅ Implemented | `owner1.c` line 20 | Auto-generates sequential IDs |
| **Feature 8: Vehicle Compatibility** | ✅ **YOUR FEATURE** | `data.h`, `booking1.c` | Validates vehicle type before booking |
| **Feature 9: Availability Control** | ✅ **YOUR FEATURE** | `data.h`, `admin1.c` | Manages Available/Booked/Maintenance status |
| **Feature 10: Auto Deactivation** | ✅ **YOUR FEATURE** | `data.c` | Deactivates unused slots after 30 days |
| **Feature 11: Location Search** | ✅ **YOUR FEATURE** | `user1.c` | Search slots by location keyword |

---

## 🎯 Quick Demo Flow (5 minutes)

1. **Register Owner** → Add Slot with Vehicle Type
2. **Login Admin** → Approve Slot → Set Maintenance → Change back to Available
3. **Register User** → Search by Location → Book with matching vehicle type
4. **Try Wrong Vehicle Type** → Show error
5. **Show Auto-Deactivation** → Explain on startup

---

## 💡 Key Points to Emphasize

1. **File Persistence**: All data saves automatically
2. **Backward Compatibility**: Works with old data files
3. **Error Handling**: Clear error messages for invalid operations
4. **Status Management**: Four-state system (Available/Booked/Maintenance/Inactive)
5. **Validation**: Multiple validation checks (vehicle type, status, availability)

---

## 🔍 Testing Checklist

- [ ] Registration with duplicate username (should fail)
- [ ] Owner adds slot with vehicle type
- [ ] Admin approves slot
- [ ] Admin sets maintenance status
- [ ] User searches by location
- [ ] User books with correct vehicle type (should succeed)
- [ ] User books with wrong vehicle type (should fail)
- [ ] User tries to book maintenance slot (should fail)
- [ ] View receipt generation
- [ ] Check data files are created/updated

---

**Good luck with your presentation! 🚀**

