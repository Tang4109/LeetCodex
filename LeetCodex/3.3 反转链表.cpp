//
// Created by TANG on 2019/12/17.
//
#include<iostream>
#include "process.h"
#include "List.h"


int main33()
{
	//��������
	List<int>* list = new List<int>;
	list->inputRear(-1);
	//��ʾ����ֵ
	list->output();

	//ɾ���ڵ�
	process<int> reverse;
	LinkNode<int>* head = reverse.reverseList(list->first);
	list->first = head;
	list->output();


	
	delete list;
	list = nullptr;
	// delete head;
	// head = nullptr;
	std::cout << "Hello, World" << std::endl;
	system("pause");
	return 0;
}

