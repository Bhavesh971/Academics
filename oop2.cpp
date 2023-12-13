//#Problem Statement: develop a program in c++ to 
//create a database of student’s information system 
//containing the following information: name, roll 
//number, class, division ,date of birth, blood group, 
//contact address, telephone number, driving license 
//no. And other. Construct the database with suitable 
//member functions. Make use of constructor, default 
//constructor, copy constructor, destructor, static 
//member functions, friend class, this pointer, inline 
//code and dynamic memory allocation operators-new 
//and delete as well as exception handling.

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string className;
    string division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;
    static int count;

public:
    Student() : rollNumber(0) {
        count++;
    }

    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        className = other.className;
        division = other.division;
        dob = other.dob;
        bloodGroup = other.bloodGroup;
        contactAddress = other.contactAddress;
        telephoneNumber = other.telephoneNumber;
        drivingLicenseNo = other.drivingLicenseNo;
        count++;
    }

    ~Student() {
        count--;
    }

    static int getCount() {
        return count;
    }

    void getData();
    void displayData();
};

int Student::count = 0;

void Student::getData() {
    cout << "Enter the student name: ";
    getline(cin, name);
    cout << "Enter the roll number: ";
    cin >> rollNumber;
    cin.ignore(); // Ignore the newline character left in the buffer
    cout << "Enter class: ";
    getline(cin, className);
    cout << "Enter the division: ";
    getline(cin, division);
    cout << "Enter date of birth (dd/mm/yyyy): ";
    getline(cin, dob);
    cout << "Enter blood group: ";
    getline(cin, bloodGroup);
    cout << "Enter contact address: ";
    getline(cin, contactAddress);
    cout << "Enter telephone number: ";
    getline(cin, telephoneNumber);
    cout << "Enter driving license number: ";
    getline(cin, drivingLicenseNo);
}

void Student::displayData() {
    cout << "Student Name: " << name << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Class: " << className << endl;
    cout << "Division: " << division << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Blood Group: " << bloodGroup << endl;
    cout << "Contact Address: " << contactAddress << endl;
    cout << "Telephone Number: " << telephoneNumber << endl;
    cout << "Driving License Number: " << drivingLicenseNo << endl;
}

int main() {
    try {
        Student* students[100];
        int n = 0;
        char ch;

        do {
            students[n] = new Student;
            students[n]->getData();
            n++;
            cout << "Do you want to add another student (y/n): ";
            cin >> ch;
            cin.ignore(); // Ignore the newline character left in the buffer
        } while (ch == 'y' || ch == 'Y');

        for (int i = 0; i < n; i++) {
            cout << "----------------------------------------" << endl;
            students[i]->displayData();
            delete students[i];
        }

        cout << "--------------------------------------------" << endl;
        cout << "Total number of students: " << Student::getCount() << endl;
    } catch(const exception& e) {
        cout << "Exception occurred: " << e.what() << endl;
    }

    return 0;
}

