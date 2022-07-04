#include<iostream>
#include "linkedlist.h"
#include "complex.h"

using namespace std;

LinkedList :: LinkedList(){
	head = NULL;
}

LinkedList :: LinkedList(const Complex* arr){

	
}

LinkedList :: LinkedList(const LinkedList& list){

	this->head = list.head;
}

void LinkedList :: insertNode(Complex data){

    Node* n = new Node(data);
    if(head==NULL){
    	head = n;
    }
    else{

	    Node* temp = head;
	 
	    while (temp->next != NULL)
	        temp = temp->next;

	    temp->next = n;
	}
}


LinkedList& LinkedList :: operator +(const Complex& c){

	insertNode(c);

	return* this;
}

LinkedList& LinkedList :: operator +(const LinkedList& list){

	
	Node* temp = head;

	while(temp->next!=NULL){
		temp = temp->next;
	}

	temp->next = list.head;

	return *this;
}

LinkedList& LinkedList :: operator -(){


	if(head!=NULL){

		if(head->next==NULL)
			head = NULL;

		else{
			Node* temp = head;
		 
		    while (temp->next->next != NULL)
		        temp = temp->next;

		    Node* del = temp->next;
		    temp->next = NULL;
		    delete del;
		}
	}

	 return* this;  
} 

LinkedList LinkedList :: operator *(int value){

	int i=1;
	Node* temp = head;
	if(head == NULL) return LinkedList() ;
	if(value == 1){
		
		head = head->next;
		delete temp;
	}
	else{
		
		while(temp!=NULL){
			if(i==value-1){
				Node* Next = temp->next;
				temp->next = Next->next;
				delete Next;
			}

			i++;
			temp = temp->next;
		}
	}

	return *this;
}


void LinkedList :: operator =(const std::vector<Complex>& arr){

	
	int n = arr.size();
	for(int i=0; i<n; i++)
		(*this).insertNode(arr[i]);

}

LinkedList& LinkedList :: operator =(const LinkedList& list){

	head = list.head;
	return *this;
}

bool search(Complex obj,const LinkedList &list)
{
    Node *temp=list.head;
    while(temp!=NULL)
    {
        if(temp->data.getRealPart()==obj.getRealPart() and temp->data.getImagPart()==obj.getImagPart())
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void display(const LinkedList& list){
	Node* temp = list.head;

	while(temp!=NULL){
		std::cout<<temp->data.getRealPart()<<" +j"<<temp->data.getImagPart();
		if(temp->next!=NULL)
			std::cout<<"-->";

		temp = temp->next;
	}

	std::cout<<"\n";

}