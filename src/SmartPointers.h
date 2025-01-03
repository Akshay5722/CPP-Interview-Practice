#pragma once
#include <iostream>
#include <memory>

//https://www.geeksforgeeks.org/smart-pointers-cpp/

class SmartPointer
{
private:

	int* m_pointer = nullptr;

public:

	SmartPointer(int* pointer) : m_pointer(pointer) {}

	~SmartPointer() 
	{ 
		delete m_pointer; 
		m_pointer = nullptr;
	}

	int& operator*() { return *m_pointer; }

	/* call in the main program
	SmartPointer ptr(new int());
	*ptr = 20;
	cout << *ptr;
	*/

	// We don't need to call delete ptr: when the object
	// ptr goes out of scope, the destructor for it is
	// automatically called and destructor does delete ptr.
};

// Delcaration of the smart pointer 
template<class T> class SmartPrt
{

private:

	// delclaration of the pointer
	T* m_ptr = nullptr;

public:

	// Constructor
	explicit SmartPrt(T* ptr = nullptr):m_ptr(ptr){}

	// Destructor
	~SmartPrt() { delete m_ptr; m_ptr = nullptr; }

	// overloading dereferencing operator
	T& operator*() { return *m_ptr; }

	// overloading function call operator
	T* operator->() { return m_ptr; }

};

class TempRectangle
{
	int length;
	int breadth;

public:
	TempRectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}

	~TempRectangle(){}

	int area() { return length * breadth; }
};

void UseOfUniquePointer();

void UseOfSharedPointer();

// concept of move semantic lvalue ref and rvalue ref
void MoveSemantic();