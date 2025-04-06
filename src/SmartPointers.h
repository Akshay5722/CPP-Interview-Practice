#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

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
template<typename T> class SmartPrt
{

private:

	// delclaration of the pointer
	T* m_ptr = nullptr;

public:

	// Constructor
	explicit SmartPrt(T* ptr = nullptr):m_ptr(ptr){}

	// Destructor
	~SmartPrt() 
	{ 
		if(m_ptr != nullptr)
			delete m_ptr; 
		m_ptr = nullptr; 
	}

	SmartPrt(const SmartPrt& ) = delete;
	SmartPrt& operator = (const SmartPrt& ) = delete;

	SmartPrt(SmartPrt&& ptr) noexcept
	{
		m_ptr = ptr.m_ptr;
		ptr.m_ptr = nullptr;
	}

	SmartPrt& operator = (SmartPrt&& ptr) noexcept
	{
		if (this != &ptr)
		{
			if (m_ptr != nullptr)
				delete m_ptr;
			m_ptr = ptr.m_ptr;
			ptr.m_ptr = nullptr;
		}
		return *this;
	}

	// overloading dereferencing operator
	T& operator*() { return *m_ptr; }

	// overloading function call operator
	T* operator->() { return m_ptr; }

	T* get() const noexcept { return m_ptr; };

	T* release() const noexcept 
	{ 
		T* temp = m_ptr;
		m_ptr = nullptr;
		return temp;
	}

	void reset(T* ptr = nullptr)
	{
		if (m_ptr != nullptr)
			delete m_ptr;
		m_ptr = ptr;
	}

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

	~TempRectangle() { 
		try { 
			throw std::exception();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		};
	}

	int area() { return length * breadth; }
};

void UseOfUniquePointer();

void UseOfSharedPointer();

// concept of move semantic lvalue ref and rvalue ref
void MoveSemantic();