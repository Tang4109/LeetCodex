//
// Created by TANG on 2019/12/17.
//
#include<iostream>
#include "process.h"
#include "List.h"


int main32()
{
	//��������
	List<int>* list = new List<int>;
	list->inputRear(-1);
	//��ʾ����ֵ
	list->output();

	//ɾ���ڵ�
	process<int> deln;
	deln.removeNthFromEnd(list->first,2);
	list->output();

	delete list;
	list = nullptr;

	std::cout << "Hello, World" << std::endl;
	system("pause");
	return 0;
}

