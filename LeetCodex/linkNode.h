#pragma once

template<class T>
class LinkNode {
public:
	LinkNode(LinkNode<T> *ptr = NULL)
	{
		link = ptr;
	}

	LinkNode(const T& item, LinkNode<T> *ptr = NULL) {
		data = item;
		link = ptr;
	}
public:
	T data;
	LinkNode<T> *link;
};

