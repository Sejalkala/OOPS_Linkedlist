#include<iostream>
#include <stdlib.h>
#include<vector>
#include "linkedlist.h"
#include "complex.h"

using namespace std;

int main(){


	int option;
	LinkedList list;
	while(1){
		cout<<"0.to exit\n1.insert a node in linkedlist at last \n2.delete last node\n
			3.delete a element at specified index\n4.create a list from array\n
			5.add a complex integer to list\n6.add a list to list\n7.search in linked list\n";
		cout<<"enter your option";
		cin>>option;
		switch(option){

			case 0:
			{
				cout<<"program terminated"<<std::endl;
				exit(0);
			}
			
			case 1:
			{
				cout<<"enter complex number"<<std::endl;
				cout<<"enter real part:";
				float real;
				cin>>real;
				cout<<"enter imaginary part:";
				float imag;
				cin>>imag;
				Complex c(real,imag);
				list.insertNode(c);
				display(list);
				break;

			}

			case 2:
			{

				
				list = -list;
				display(list);
				break;
			}

			case 3:
			{

				int index;
				cout<<"enter index of element you want to delete(indexing start from 1):";
				cin>>index;
				list = list*index;
				display(list);
				break;

			}

			case 4:
			{

				int n;
				float real,imag;
				LinkedList temp;
				vector<Complex>vec;
				cout<<"enter no of elements:";
				cin>>n;
				cout<<"enter the elements\n";
				for(int i=0; i<n; i++){
					cout<<"===================="<<std::endl;
					cout<<"enter real part:";
					cin>>real;
					cout<<"enter imaginary part:";
					cin>>imag;
					Complex c(real,imag);
					vec.push_back(c);

				}
				temp = vec;
				display(temp);
				break;
			}

			case 5:
			{
				float real,imag;
				cout<<"enter complex number:"<<endl;
				cout<<"enter real part:"<<endl;;
				cin>>real;
				cout<<"enter imaginary part:";
				cin>>imag;

				Complex c(real,imag);

				list = list + c;
				display(list);
				break;

			}

			case 6:
			{
				int n;
				LinkedList temp;
				float real,imag;
				cout<<"enter no of elements in list:";
				cin>>n;
				cout<<"enter the elements of list\n";
				for(int i=0; i<n; i++){
					cout<<"===================="<<endl;
					cout<<"enter real part:"<<endl;;
					cin>>real;
					cout<<"enter imaginary part:"<<endl;;
					cin>>imag;
					Complex c(real,imag);

					temp.insertNode(c);
				}
				cout<<endl;

				list = list + temp;

				display(list);
				break;
			}
			case 7:
			{
			 	cout<<"\n Enter the real and imaginary number of a new complexInteger object. To check its presence in Linked List 3"<<endl;
				int rvalue2,ivalue2;
				cin>>rvalue2>>ivalue2;
				Complex newobj(rvalue2,ivalue2);
				if(search(newobj,list))
				{
					cout<<"present"<<endl;
				}
				else
				{
					cout<<"not present"<<endl;
				}
			}
		}
	}
	
}
