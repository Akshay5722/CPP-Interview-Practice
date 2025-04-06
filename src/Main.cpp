// SampleSolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "OperatorOverloading.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "SmartPointers.h"
#include "ThreadingOperations.h"
#include "ArrayProblems.h"

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
    int load = 5;
	switch (load)
	{
		// Case 1: Operator overloading 
	case 1:
	{
		OperatorOverloading();
		Base pBase;//new Derived();
		int a = sizeof(pBase);
		//delete pBase;
		break;
	}
	case 2:
	{
		//TestLinkedListInsertionProblems();
		//TestLinkedListDeletionProblems();
		TestLinkedListProblems();
		break;
	}
	case 3:
	{
		TestDoublyLinkedListInserrtionProblem();
		break;
	}
	case 4:
	{
		// use of smart pointers
		UseOfSharedPointer();
	}
	case 5:
	{
		// threading operations
		// 1. Launcing the thread
		//fizzbuzzGameInOtherThread();

		//2. Thread handle method
		//threadHandleOperation();

		//3. threading exeption handling using wrapper calss
		//handlethreadException();

		//4. Data Races
		//DataRaces();

		// 5. Data races solved using critical section
		//DataRacesSolvedUsingCriticalSection();

		// 6. Data races solved using Mutex
		DataRacesSolvedUsingMutex();
		break;
	}
	case 6:
	{
		if (1)
		{
			try {
				TempRectangle* temp = new TempRectangle(10, 5);
				delete temp;
			}
			catch (std::exception &e)
			{
				std::cout << e.what();
				// TODO
			}
			catch (...)
			{
				std::cout << "Unknown_exception" << std::endl;
			}
		}

		std::vector<int> array = { 5, 9, 4,2,8,7,1,3, 11,23,20,16,22,17,15 };
		SortArray(array);
	}
	default:
		break;
	}
}
