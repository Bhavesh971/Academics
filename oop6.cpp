//#ASSIGNMENT-4
//#probem statement: Write C++ program using STL
//for sorting and searching user defined records such as
//Item records (Item code, name, cost, quantity etc) using
//vector container.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class item
{
public:
char name[30];
int quantity;
int cost;
int code;
bool operator==(const item& i1)
 {
 return (code == i1.code);
 }
bool operator<(const item&i1)
{
return code<i1.code;
}
};
vector<item>o1;
void print(item &i1);
void display();
void insert();
void search();
bool compare(const item& i1 ,const item& i2)
{
if(i1.code==i2.code)
return 1;
if(i1.code<i2.code)
return 1;
else
return 0;
}
int main()
{
int ch;
do{
cout<<"\n----MENU----"<<endl;
cout<<"1.insert"<<endl;
cout<<"2.Display"<<endl;
cout<<"3.Search"<<endl;
cout<<"4.sort"<<endl;
cout<<"5.Delete"<<endl;
cout<<"6.Exit"<<endl;
cout<<"enter your choice: ";
cin>>ch;
switch(ch)
{
case 1: 
 insert();
break;
case 2:
 display();
break;
case 3:
search();
break;
case 4:sort(o1.begin(),o1.end(),compare);
cout<<"\n\n sorted on cost: ";
display();
break;
case 5: exit(0);
}
}while(ch!=6);
return 0;
}
void insert()
{
item i1;
cout<<"enter the item name: ";
cin>>i1.name;
cout<<"enter the quantity of item: ";
cin>>i1.quantity;
cout<<"enter the cost of item: ";
cin>>i1.cost;
cout<<"enter the code of item: ";
cin>>i1.code;
o1.push_back(i1);
}
void display()
{
for_each(o1.begin(),o1.end(),print);
}
void print(item & i1)
{
cout<<endl;
cout<<"item name: "<<i1.name<<endl;
cout<<"Item qauntity: "<<i1.quantity<<endl;
cout<<"cost of item: "<<i1.cost<<endl;
cout<<"Item code"<<i1.code;
}
void search()
{
vector<item>::iterator p;
item i1;
cout<<"enter the item code to serach: "<<endl;
cin>>i1.code;
p=find(o1.begin(),o1.end(),i1);
if(p==o1.end())
{
cout<<"Not found ";
}
else
cout<<"found"<<endl;
cout<<"item name:"<<p->name<<endl;
cout<<"item code:"<<p->code<<endl;
cout<<"item cost:"<<p->cost<<endl;
cout<<"item quantity:"<<p->quantity<<endl;
}
