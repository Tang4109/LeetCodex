#pragma once
#include "linkNode.h"

template <typename T>
class process
{
public:
	void deleteNode(LinkNode<T>* node);
	LinkNode<T>* removeNthFromEnd(LinkNode<T>* head, int n);
	LinkNode<T>* reverseList(LinkNode<T>* head);
};

template <typename T>
void process<T>::deleteNode(LinkNode<T>* node)
{
	node->data = node->link->data;
	node->link = node->link->link;
}

template <typename T>
LinkNode<T>* process<T>::removeNthFromEnd(LinkNode<T>* head, int n)
{
	LinkNode<T>* right = head;
	LinkNode<T>* left = head;
	for (int i = 0; i < n; i++)
	{
		right = right->link;
	}

	if (right == nullptr)
	{
		head = head->link;
		return head;
	}
	while (right->link != nullptr)
	{
		left = left->link;
		right = right->link;
	}
	left->link = left->link->link;
	return head;
}

template <typename T>
LinkNode<T>* process<T>::reverseList(LinkNode<T>* head)
{
	if ((head == nullptr) || (head->link == nullptr))
	{
		return head;
	}
	// 使用三个额外的指针记录
	LinkNode<T>* p = head->link;
	LinkNode<T>* q = p->link;
	LinkNode<T>* r = q->link;
	// 头节点变为尾节点，先将头结点指向NULL
	p->link = nullptr;
	while (r != nullptr)
	{
		// 反向指针
		q->link = p;
		// 三个指针向后移动一步
		p = q;
		q = r;
		r = r->link;

	}
	// r为NULL时还要最后更改一个指向
	q->link = p;
	//添加一个头结点
	LinkNode<T>* newHead = new LinkNode<T>;
	newHead->link = q;
	
	return newHead;
}
