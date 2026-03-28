Project Documentation: Student Course Management System
1. Executive Summary
The Student Course Management System is a robust console-based application developed in C++. It is designed to manage academic records efficiently using Object-Oriented Programming (OOP) principles. The system allows administrators to handle student profiles, academic performance (GPA), and course enrollments, ensuring data persistence through file handling.
________________________________________

2. Core Features
•	Student Administration: Create new student profiles with unique IDs and remove existing records.
•	Course Enrollment: Assign students to specific courses with built-in validation to prevent duplicate enrollments.
•	Data Persistence: Save and load all system data to/from a local text file (data.txt), ensuring no information is lost between sessions.
•	Academic Sorting: View a ranked list of students based on their GPA in descending order.
•	Search Capabilities: Instantly find student details using either their Unique ID or Full Name.
•	Input Reliability: Integrated error handling to manage invalid user inputs (e.g., entering text instead of numbers).
________________________________________

3. System Architecture (OOP Design)
The project is modularized into four main components to ensure clean code and easy maintenance:
1.	Person.h (Base Class): Defines general attributes like name.
2.	Student.h (Derived Class): Inherits from Person and adds specific attributes such as id, gpa, and a vector of courses.
3.	StudentManagementSystem.h (Logic Layer): The engine of the project. It uses an std::map to store students for $O(\log n)$ lookup speed and handles all CRUD (Create, Read, Update, Delete) operations.
4.	main.cpp (Presentation Layer): Provides a user-friendly menu interface for interacting with the system.
6. Key Functions & Logic Implementation
A. Dynamic Data Storage (std::map)
The system utilizes std::map<int, Student> to store records.
•	Why? It provides an efficient way to access any student's data using their Unique ID as a key, ensuring no two students share the same ID.
•	Lookup Speed: $O(\log n)$, which is significantly faster than a standard list or array for large datasets.
B. Course Enrollment Logic
C++
bool enrollInCourse(string courseName) {
    for (string c : courses) {
        if (c == courseName) return false; 
    }
    courses.push_back(courseName);
    return true;
}
•	Mechanism: Before adding a new course to the student's vector, the function iterates through existing courses to check for duplicates. It returns true if the enrollment is successful and false if the student is already registered.
C. Custom Sorting (GPA Ranking)
To rank students, the system transfers data from the map to a std::vector and applies the std::sort algorithm with a custom Comparator:
C++
sort(v.begin(), v.end(), [](Student a, Student b) { 
    return a.getGpa() > b.getGpa(); 
});
•	Logic: This sorts the students in descending order (from highest GPA to lowest).
D. File Serialization (Save/Load)
•	Save: Iterates through the map and writes each student's data into data.txt using a delimiter (|) to separate fields (ID, Name, GPA, Courses).
•	Load: Reads the file line by line, parses the strings using std::stringstream, and reconstructs the Student objects back into the system's memory.
________________________________________

7. Conclusion
This project demonstrates a practical application of C++ advanced features. By separating the concerns into different classes and handling data persistently, the system provides a scalable foundation for academic management tasks.
________________________________________

