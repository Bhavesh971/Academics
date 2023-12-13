//Assignment-1
//#Problem Statement:: Implement a class Complex which 
//represents the Complex Number data type. Implement the following
//1.Constructor (including a default constructor which creates the 
//complex number 0+0i).
//2.Overload operator+ to add two complex numbers.
//3.Overload operator* to multiply two complex numbers.
//4.Overload operators << and >> to print and read Complex Numbers


#include <iostream>
using namespace std;

class complex{
	public:
		float real;
		float img;
		complex(){
			real = 0;
			img = 0;
		}
		friend istream& operator>>(istream& ,complex&);
		friend ostream& operator<<(ostream& ,complex&);
		complex operator+(const complex&);
		complex operator*(const complex&);
		

};
istream& operator>>(istream &input ,complex &t){
			cout<<"Enter the real part";
			input>>t.real;
			cout<<"Enter the imaginary part";
			input>>t.img;
			return input;
		}
ostream& operator<<(ostream &out ,complex &t){
			out<<t.real<<"+"<<t.img<<"i\n";
			return out;
		}

 
complex complex::operator +(const complex& c1){
	complex temp;
	temp.real = real + c1.real;
	temp.img = img + c1.img;
	return temp;
}
complex complex::operator*(const complex& c2){
	complex temp2;
	temp2.real = real*c2.real - img*c2.img;
	temp2.img = img*c2.real + real*c2.img;
	return temp2;
}
int main() {
 complex c1, c2, c3, c4;
 cout << "default complex number is: " << endl;
 cout << c1 << endl;
 cout << c2 << endl;
 cout << "Enter the real and imaginary part of the complex number 1: " << endl;
 cin >> c1;
 cout << "Enter the real and imaginary part of the complex number 2: " << endl;
 cin >> c2;
 cout << "complex number 1: " << c1 << endl;
 cout << "complex number 2: " << c2 << endl;
 c3 = c2 + c1;
 cout << "addition: " << c3 << endl;
 c4 = c1 * c2;
 cout << "multiplication: " << c4 << endl;
 return 0;
}
