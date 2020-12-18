#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

template <class E>

class Stack
{
public:
	virtual E pop() = 0;//virtual puro
	virtual E top() = 0;//virtual puro
	virtual void push(E) = 0;//virtual puro
	virtual int search(E) = 0;//virtual puro
	virtual const int size() = 0;//virtual puro
	virtual const bool empty() = 0;//virtual puro
};
