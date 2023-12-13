//Assignment-5
//#Problem Statement:Write a function template for selection sort that inputs, sorts and outputs an integer array
//and a float array.
#include <iostream>
using namespace std;
template<typename T>
void selection_sort(T arr[],int size){
	for (int i=0;i<size-1;++i){
		int minindex=i;
		for (int j=i+1;j<size;++j){
			if (arr[j]<arr[minindex]){
				minindex=j;
	
			}
		}
		if(minindex != i){
			
			T temp = arr[i];
			arr[i] = arr[minindex];
			arr[minindex]= temp;
		}
	}
}

template<typename T>
void print(T arr[],int size){
	for (int i =0;i<size;++i){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	const int maxsize =100;
	int intsize,floatsize;
	int intArray[maxsize];
	float floatArray[maxsize];
	cout<<"Enter the number of Integers: "<<endl;
	cin>>intsize;
	for (int i =0; i<intsize;++i){
	cout<<"Enter the integer number : "<<endl;
	cin>>intArray[i];
	}
	cout<<"Enter the number of Floats: "<<endl;
	cin>>floatsize;
	for (int i =0; i<floatsize;++i){
	cout<<"Enter the float number : "<<endl;
	cin>>floatArray[i];
	}
	cout<<endl;
	cout<<"Integer Array Before Sorting:"<<endl;
	print(intArray, intsize);
    selection_sort(intArray, intsize);
    cout<<"Integer Array After Sorting:"<<endl;
	print(intArray, intsize);
	
	cout << "\nFloat Array before sorting: ";
    print(floatArray, floatsize);
    selection_sort(floatArray, floatsize);
    cout << "Float Array after sorting: ";
    print(floatArray, floatsize);

	
}
