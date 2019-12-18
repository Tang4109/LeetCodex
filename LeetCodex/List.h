#pragma once
#include "linkNode.h"

template <class T>
class List
{
public:
	List();

	~List();

	void makeEmpty();

	void inputRear(T endTag);

	void output();

	LinkNode<T>* Locate(T val);

public:
	LinkNode<T>* first;
};

template<class T>
List<T>::List()
{
	first = new LinkNode<T>;
}

template<class T>
List<T>::~List()
{
	makeEmpty();
	delete first;
	first = nullptr;
}

template <class T>
void List<T>::makeEmpty()
{
	//½«Á´±íÖÃ¿Õ
	LinkNode<T>* q;
	while (first->link != nullptr)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

template <class T>
void List<T>::output()
{
	LinkNode<T>* current = first->link;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->link;
	}
	std::cout << std::endl;
}

template <class T>
void List<T>::inputRear(T endTag)
{
	LinkNode<T>* newNode;
	LinkNode<T>* last;
	T val;
	makeEmpty();
	std::cin >> val;
	last = first;
	while (val != endTag)
	{
		newNode = new LinkNode<T>(val);
		last->link = newNode;
		last = newNode;
		std::cin >> val;
	}
	last->link = nullptr;
}

template <class T>
LinkNode<T>* List<T>::Locate(T val)
{

	LinkNode<T>* current = first;
	int k = 0;
	while (current != nullptr && current->data != val)
	{
		current = current->link;
		k++;
	}
	return current;
}


