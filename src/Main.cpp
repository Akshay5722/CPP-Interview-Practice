// SampleSolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OperatorOverloading.h"

// Check operator overloading and the copy constuction  activity
void OperatorOverloading()
{
	double h = 5.0, w = 6.0, l = 9.0;
	Box box1(h, w, l);
	// Copy costructor call
	Box box2 = box1;

	// Assignment operator call
	Box box3;
	box3 = box1;

	// Equality operator
	bool isEqual = (box3 == box1);
	int debug = 0;
	debug = 1;
}

int main()
{
    int load = 1;
	switch (load)
	{
		// Case 1: Operator overloading 
	case 1:
	{
		OperatorOverloading();
		break;
	}
	default:
		break;
	}
}
