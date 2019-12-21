#pragma once
#include "linkNode.h"


template <typename T>
class process
{
public:
	void deleteNode(LinkNode<T>* node);
	LinkNode<T>* removeNthFromEnd(LinkNode<T>* head, int n);
	LinkNode<T>* reverseList(LinkNode<T>* head);
	LinkNode<T>* mergeTwoLists(LinkNode<T>* l1, LinkNode<T>* l2);
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

template <class T>
LinkNode<T>* process<T>::mergeTwoLists(LinkNode<T>* l1, LinkNode<T>* l2)
{
	LinkNode<T>* head1 = l1;
	LinkNode<T>* head2 = l2;
	l1 = l1->link;
	l2 = l2->link;
	//ɾ��ͷ�ڵ�
	delete head1,head2;
	head1 = head2 = NULL;
	
	//���ж�������Ϊ�յ����
	if (l1 == nullptr)
	{
		return l2;
	}
	if (l2 == nullptr)
	{
		return l1;
	}

	//�½�һ��ͷ�����Ϊ����
	LinkNode<T>* head = new LinkNode<T>;
	LinkNode<T>* currentNOde = head;

	while (l1 || l2)
	{
		if (l1 == nullptr)
		{
			currentNOde->link = l2;
			break;
		}
		if (l2 == nullptr)
		{
			currentNOde->link = l1;
			break;
		}

		//�жϴ�С
		if (l1->data <= l2->data)
		{
			currentNOde->link = l1;
			currentNOde = currentNOde->link;
			l1 = l1->link;
		}
		else
		{
			currentNOde->link = l2;
			currentNOde = currentNOde->link;
			l2 = l2->link;
		}
	}
	return head;
}
