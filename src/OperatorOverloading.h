#pragma once

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
	Box operator = (Box& box);
	bool operator == (Box& box);
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
