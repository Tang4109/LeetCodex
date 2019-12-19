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
	// ʹ�����������ָ���¼
	LinkNode<T>* p = head->link;
	LinkNode<T>* q = p->link;
	LinkNode<T>* r = q->link;
	// ͷ�ڵ��Ϊβ�ڵ㣬�Ƚ�ͷ���ָ��NULL
	p->link = nullptr;
	while (r != nullptr)
	{
		// ����ָ��
		q->link = p;
		// ����ָ������ƶ�һ��
		p = q;
		q = r;
		r = r->link;

	}
	// rΪNULLʱ��Ҫ������һ��ָ��
	q->link = p;
	//���һ��ͷ���
	LinkNode<T>* newHead = new LinkNode<T>;
	newHead->link = q;
	
	return newHead;
}
