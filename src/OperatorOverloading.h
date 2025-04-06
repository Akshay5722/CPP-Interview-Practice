#pragma once
#include <iostream>

class Box
{
private:
	double height = 0;
	double* width = nullptr;
	double length = 0;

public:
	Box();
	~Box();
	Box(double& h, double& w, double& len);
	Box(Box& box);
	Box operator = (const Box& box);

	bool operator == (const Box& box);
};


// Move constructor and Move assignment operator
class MoveObjectClass
{
private:
	int* m_data = nullptr;

public:
	// constructor
	MoveObjectClass(int* data): m_data(data){}

	~MoveObjectClass()
	{
		delete[] m_data;
	}

	// move constructor
	MoveObjectClass(MoveObjectClass&& object)
	{
		m_data = object.m_data;
		object.m_data = nullptr;
	}

	// move assignment operator
	MoveObjectClass& operator=(MoveObjectClass&& object)
	{
		if (this != &object)
		{
			delete[] m_data;

			m_data = object.m_data;
			object.m_data = nullptr;
		}
		return *this;
	}
};


class Base
{
	int a;
public:
	Base(): a(0)
	{
		std::cout << "Constructor Base \n";
	}

	virtual void function()
	{
		std::cout << "Base Func..\n";
	}

	~Base() 
	{
		std::cout << "Destructor Base\n";
	}
};

class Derived : public Base
{
public:
	Derived(): Base()
	{
		std::cout << "Constructor Derived\n";
	}

	void function()
	{
		std::cout << "Derived Func..\n";
	}

	~Derived()
	{
		std::cout << "Destructive Derived\n";
	}
};