//
// Created by TANG on 2019/12/17.
//
#include<iostream>
#include "process.h"
#include "List.h"


int main()
{
	//��������
	List<int>* list1 = new List<int>;
	List<int>* list2 = new List<int>;
	List<int>* list3 = new List<int>;
	list1->inputRear(-1);
	list2->inputRear(-1);
	//��ʾ����ֵ
	list1->output();
	list2->output();

	//ɾ���ڵ�
	process<int> merge;
	LinkNode<int>* head = merge.mergeTwoLists(list1->first,list2->first);
	list3->first = head;
	list3->output();



	//list1��list2�Ѿ��ϲ���list3;list1��list2��ͷ�ڵ���mergeTwoLists������ɾ��
	delete list3;
	list3 = nullptr;

	std::cout << "Hello, World" << std::endl;
	system("pause");
	return 0;
}

