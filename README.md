# Smart Parking Management System

A console-based parking management system written in C that allows users to register, login, and manage parking slots with different roles (Admin, Owner, User).

## Features

- **User Registration & Login**: Secure authentication with file-based user management
- **Admin Panel**: Approve pending parking slots, view all slots, set maintenance status
- **Owner Panel**: Add new parking slots with vehicle type specification
- **User Panel**: View available slots, search by location, book parking slots
- **Vehicle-Type Compatibility**: Booking validation based on vehicle type (Car/Bike/Truck)
- **Slot Availability Control**: Manage slots in Available, Booked, or Maintenance status
- **Auto Deactivation**: Slots automatically deactivate after 30 days of inactivity
- **Location-Based Search**: Find nearby parking slots by location
- **Data Persistence**: All data saved to files automatically

## Requirements

- GCC Compiler (MinGW on Windows)
- Code::Blocks IDE (optional)

## How to Compile and Run

### Using Code::Blocks
1. Open `Smart-Parking.cbp` in Code::Blocks
2. Press **F9** to Build
3. Press **F10** to Run

### Using Command Line
```bash
gcc -o Smart-Parking main.c data.c admin1.c owner1.c user1.c booking1.c confirmation1.c auth1.c
./Smart-Parking
```

## Project Structure

- `main.c` - Entry point and main menu
- `data.c/h` - Data structures and file I/O
- `admin1.c/h` - Admin functionality
- `owner1.c/h` - Owner functionality
- `user1.c/h` - User functionality
- `booking1.c/h` - Booking system
- `auth1.c/h` - Authentication system
- `confirmation1.c/h` - Receipt generation

## Usage

1. **Register** a new account (Admin/Owner/User)
2. **Login** with your credentials
3. Navigate through role-specific menus:
   - **Admin**: Approve slots, view all slots, set maintenance
   - **Owner**: Add slots, view your slots
   - **User**: Search slots, book parking

## Data Files

- `users.txt` - User credentials
- `slots.txt` - Parking slot data
- `receipt.txt` - Generated receipts

## Contributors

- Member-2: Slot & Owner Management
- Member-3: Booking & User Management
