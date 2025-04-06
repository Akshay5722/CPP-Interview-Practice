
#include "SmartPointers.h"

void UseOfUniquePointer()
{
	std::unique_ptr<TempRectangle> obj(new TempRectangle(10, 15));
	if (obj != nullptr)
	{
		std::cout << "Rectangle1 Area = " << obj->area() << std::endl;
	}

	std::unique_ptr<TempRectangle> obj2;
	obj2 = std::move(obj);
	if (obj2 != nullptr)
	{
		std::cout << "Rectangle2 Area = " << obj2->area() << std::endl;
	}
}

void UseOfSharedPointer()
{
	// Created a object of a shared pointer
	auto shareP1 = std::make_shared<TempRectangle>(10, 20);

	// print the use count of this pointer
	std::cout << "Ref Count of ShareP1 = " << shareP1.use_count() << std::endl;

	if (1)
	{
		std::shared_ptr<TempRectangle> shareP2;
		shareP2 = shareP1;

		// print the use count of this pointer
		std::cout << "Ref Count of ShareP1 = " << shareP1.use_count() << std::endl;
		std::cout << "Ref Count of ShareP2 = " << shareP2.use_count() << std::endl;
		shareP2.reset();
		// print the use count of this pointer
		std::cout << "Ref Count of ShareP1 after Reset = " << shareP1.use_count() << std::endl;
		std::cout << "Ref Count of ShareP2 after Reset = " << shareP2.use_count() << std::endl;
	}

	std::cout << "Ref Count of ShareP1 = " << shareP1.use_count() << std::endl;

}


void MoveSemantic()
{
	// lvalue referene is nothing the object occupiees 
	// the already assigned memory locationa of the same type of vartiable
	// denotaed by the &
	int x = 1;
	int* xp = &x;

	//
}