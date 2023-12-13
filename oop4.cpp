//ASSIGNMENT 4
//#PROMBLE STATEMENT: Write a C++ program that creates an
//output file, writes information to it, closes the file, open it again as an
//input file and read the information from the file.
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class file {
    string name;
    int salary;

public:
    void readfile();
    void writefile();
};

void file::writefile() {
    ofstream out("data.txt", ios::out);
    out << "Employee name" << "\t" << "Employee Salary" << endl;
    int n;
    cout<<"Enter the number of employees:";
    cin>>n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the name of Employee " << i + 1 << ": ";
        cin.ignore(); // Clear the buffer
        getline(cin, name);
        cout << "Enter the Salary of Employee " << i + 1 << ": ";
        cin >> salary;
        out << name << "\t\t" << salary << endl;
    }
    out.close();
}

void file::readfile() {
    ifstream in("data.txt", ios::in);
    cout << "-----Data from the file-----" << endl;
    string line;
    getline(in, line); // Read and discard the header line
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();
}

int main() {
    file f1;
    f1.writefile();
    f1.readfile();
    return 0;
}

