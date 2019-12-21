//
// Created by TANG on 2019/12/17.
//
#include<iostream>
#include "process.h"
#include "List.h"


int main()
{
	//创建链表
	List<int>* list1 = new List<int>;
	List<int>* list2 = new List<int>;
	List<int>* list3 = new List<int>;
	list1->inputRear(-1);
	list2->inputRear(-1);
	//显示链表值
	list1->output();
	list2->output();

	//删除节点
	process<int> merge;
	LinkNode<int>* head = merge.mergeTwoLists(list1->first,list2->first);
	list3->first = head;
	list3->output();



	//list1和list2已经合并到list3;list1和list2的头节点在mergeTwoLists函数中删除
	delete list3;
	list3 = nullptr;

	std::cout << "Hello, World" << std::endl;
	system("pause");
	return 0;
}

