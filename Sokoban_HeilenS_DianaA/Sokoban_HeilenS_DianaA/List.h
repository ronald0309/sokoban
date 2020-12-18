#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include "Iterator.h"
using namespace std;

template <class E>

class List
{
protected:
	int tam = 0;
public:
	virtual const int size();
	virtual const bool empty();
	virtual List<E>* add(E) = 0;//virtual puro
	virtual List<E>* addAll(List<E>*) = 0;//virtual puro
	virtual E remove(int) = 0;//virtual puro
	virtual E get(int) = 0;
	virtual Iterator<E>* iterator() = 0;
	virtual const string toString() = 0;
};

template<class E>
inline const int List<E>::size()
{
	return tam;
}

template<class E>
inline const bool List<E>::empty()
{
	return tam == 0;
}