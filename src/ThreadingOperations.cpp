#include "ThreadingOperations.h"

#include <thread>
#include <vector>
#include <string>
#include <iostream>

void ThreadingOperations::operator()(const int& a)
{
	int count = 0; int product = 1;
	while (count <= a)
	{
		product = product*count;
	}
}

int ThreadingOperations::Function(const int& a, const int& b)
{
	return a * b;
}

int ThreadingOperations::statFunction(const int& a, const int& b)
{
	return a * b;
}

void FreeBuzzGameFun()
{
	std::vector<std::string> allChild{ "Abdul", "Bart", "claudia", "Divya" };
	int n = 1;
	while (n <= 30)
	{
		for (auto child : allChild)
		{
			if (n % 3 == 0 && n % 5 == 0)
				std::cout << child << " says" << " fizzbuzz" << std::endl;
			else if (n % 3 == 0)
				std::cout << child << " says" << " fizz" << std::endl;
			else if (n % 5 == 0)
				std::cout << child << " says" << " buzz" << std::endl;
			else 
				std::cout << child << " says " << n << std::endl;
		}
		n++;
	}

	// sleep thread for the 5 seconds
	std::this_thread::sleep_for(std::chrono::seconds(5));
}

void fizzbuzzGameInOtherThread()
{
	std::thread t1(FreeBuzzGameFun);
	t1.join();
}

void LaunchingTheThreadsUsingDifferentFunctions()
{
	// launching the thread using a global function
	std::thread t1(FreeBuzzGameFun);

	// launching the thread using Lambada function
	auto LambadaFun = [](int a, int b)
	{
			return a + b;
	};

	std::thread t2(LambadaFun, 5, 9);

	// Launching the threads using the function object of class
	int a = 5;
	std::thread t3(ThreadingOperations(), a);

	// Launching the thread using function of a class
	ThreadingOperations obj; int b = 8;
	std::thread t4(&ThreadingOperations::Function, &obj, a, b);

	// Launching the thread using static function of class
	// Wrap the refeence argument by using std::ref and const reference argumant using std::cref
	std::thread t5(ThreadingOperations::statFunction, std::ref(a), std::cref(b));

	// wait until threads complete their operations
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
}