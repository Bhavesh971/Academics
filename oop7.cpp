//Assigment 7
//#PROMBLE STATEMENT: Write a program in C++ to use 
//map associative container. The keys will be the names of states
//and the values will be the populations of the states. When the 
//program runs, the user is prompted to type the name of a state. 
//The program then looks in the map, using the state name as an
//index and returns the population of the state.

#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	map<string,int>m;
	map<string,int>::iterator it;
	m.insert(pair<string,int>("Maharastra",10));
	m.insert(pair<string,int>("Goa",20));
	m.insert(pair<string,int>("Mumbai",30));
	m.insert(pair<string,int>("Haryana",40));
	m.insert(pair<string,int>("Delhi",50));
	m.insert(pair<string,int>("Gujrat",60));
	cout<<"Total number of states with Population"<<m.size()<<endl;
	cout<<"-----------------------------------------"<<endl;
	for (it=m.begin();it!=m.end();it++){
		cout<<it->first<<":"<<it->second<<" million"<<endl;
	}
	char c;
	do{
		string state;
		cout<<"Enter the name of state: "<<endl;
		cin>>state;
		it = m.find(state);
		if(it!=m.end()){
			cout<<state<<"= "<<it->second<<" million"<<endl;
			
		}
		else{
			cout<<"State not found"<<endl;;
		}
		cout<<"Do you want to continue y|n:";
		cin>>c;
	}while(c =='y'||c=='Y');
	return 0;
}
