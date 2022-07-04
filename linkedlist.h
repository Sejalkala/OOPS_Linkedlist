#ifndef LINKED_LIST_H
#define LINKED_LIST_H 1

#include<vector>
#include "complex.h"

class Node{

public:
	Complex data;
	Node* next;

	Node(Complex data){
		this->data = data;
		next = NULL;
	}
};

class LinkedList{

	
public:
Node* head;

	LinkedList();
	LinkedList(const Complex* arr);
	LinkedList(const LinkedList& list);

	void insertNode(Complex data);
	friend void display(const LinkedList& list);
	friend bool search(Complex obj,const LinkedList &);
	LinkedList& operator +(const Complex& c);
	LinkedList& operator +(const LinkedList& list);
	LinkedList& operator -();
	LinkedList operator *(int n);
	LinkedList& operator =(const LinkedList& list);
	void operator =(const std::vector<Complex>& arr);

};

#endif
