//Assignment-3
//#Problem Statement: Imagine a publishing company 
//which does marketing for book and audiocassette versions. 
//Create a class publication that stores the title (a string) and 
//price (type float) of a publication .From this class derive two 
//classes: book, which adds a page count(type int),
//and tape, which adds a playing time in minutes(type float). 
//Write a program that instantiates the book and tape classes, 
//allows user to enter data and displays the data members .If 
//an exception is caught, replace all the data member values 
//with zero values.


#include <iostream>
#include <string>
using namespace std;

class publication {
public:
    string title;
    float price;

    publication() {
        title = " ";
        price = 0.0;
    }

    publication(string t, float p) {
        title = t;
        price = p;
    }
};

class book : public publication {
public:
    int pagecount;

    book() {
        pagecount = 0;
    }

    book(string t, float p, int pc) : publication(t, p) {
        pagecount = pc;
    }

    void getData() {
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter book price: ";
        cin >> price;
        cout << "Enter page count: ";
        cin >> pagecount;
        cin.ignore(); // Ignore the newline character left in the buffer
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Page Count: " << pagecount << endl;
    }
};

class tape : public publication {
public:
    float playtime;

    tape() {
        playtime = 0.0;
    }

    tape(string t, float tim) : publication(t, tim) {
        playtime = tim;
    }

    void getData() {
        cout << "Enter tape title: ";
        getline(cin, title);
        cout << "Enter tape price: ";
        cin >> price;
        cout << "Enter playing time in minutes: ";
        cin >> playtime;
        cin.ignore(); // Ignore the newline character left in the buffer
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Time in Minutes: " << playtime << " minutes" << endl;
    }
};

int main() {
    try {
        book b;
        tape t;

        cout << "Enter book details:\n";
        b.getData();

        cout << "\nEnter tape details:\n";
        t.getData();

        cout << "\nBook details:\n";
        b.display();

        cout << "\nTape details:\n";
        t.display();
    } catch (...) {
        cout << "\nException caught. Resetting data to zero values.\n";
        book b;
        tape t;
        b.display();
        t.display();
    }

    return 0;
}

