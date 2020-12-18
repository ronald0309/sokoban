#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include"DoubleNode.h"

using namespace std;

template <class E>

class Iterator
{
private:
	DoubleNode<E>* node;
public:
	Iterator(DoubleNode<E>*);
	~Iterator();
	virtual E object();
	virtual int index();
	virtual bool hasNext();
	virtual void next();
	virtual void last();
};

template<class E>
inline Iterator<E>::Iterator(DoubleNode<E>* node)
{
	this->node = node;
}

template<class E>
inline Iterator<E>::~Iterator()
{
	//delete node;
}

template<class E>
inline E Iterator<E>::object()
{
	return node->getObject();
}

template<class E>
inline int Iterator<E>::index()
{
	return node->getIndex();
}
	
template<class E>
inline bool Iterator<E>::hasNext()
{
	return node != NULL;
}

template<class E>
inline void Iterator<E>::next()
{
	node = node->getSig();
}

template<class E>
inline void Iterator<E>::last()
{
	node = node->getAnt();
}
