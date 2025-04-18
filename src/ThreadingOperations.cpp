#include "ThreadingOperations.h"

#include <thread>
#include <vector>
#include <string>
#include <windows.h>
#include <iostream>
#include <mutex>

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
			n++;
		}	
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

void threadHandleOperation()
{
	std::cout << "Main Thread ID = " << std::this_thread::get_id() << std::endl;
	int a = 5, b = 6;
	std::thread thrObj(ThreadingOperations::statFunction, std::ref(a), std::cref(b));
	std::cout << "Thread Object ID = " << thrObj.get_id() << std::endl;
	std::cout << "Thread ID = " << std::this_thread::get_id() << std::endl;

	std::cout << "ThreadHandle: " << thrObj.native_handle() << std::endl;
	thrObj.join();
}

void handlethreadException()
{	
	try
	{
		std::thread t1(ThreadingOperations::statFunction, 5, 10);
		thread_guard thrdGuard(std::move(t1));
		throw std::exception(); // here destructor of thread_guard called 
								// and join called over thread object
	}
	catch (std::exception& e)
	{
		std::cout << "Exception thrown" << std::endl;
	}
}

void DataRaces()
{
	int val = 0;

	auto fun = [&val]()
	{
		for (size_t i = 0; i < 100000; i++)
		{
			val++;
		}
	};

	std::thread t1(fun);
	std::thread t2(fun);
	std::thread t3(fun);

	t1.join();
	t2.join();
	t3.join();

	std::cout << val << std::endl;
}

void DataRacesSolvedUsingCriticalSection()
{
	int val = 0;
	CRITICAL_SECTION cs;

	auto fun = [&val, &cs]()
	{
		EnterCriticalSection(&cs);
		for (size_t i = 0; i < 100000; i++)
		{
			val++;
		}
		LeaveCriticalSection(&cs);
	};

	InitializeCriticalSection(&cs);
	std::thread t1(fun);
	std::thread t2(fun);
	std::thread t3(fun);

	t1.join();
	t2.join();
	t3.join();
	DeleteCriticalSection(&cs);
	std::cout << val << std::endl;
}

void DataRacesSolvedUsingMutex()
{
	int val = 0;
	std::mutex cs;

	auto fun = [&val, &cs]()
	{
		std::lock_guard<std::mutex> lock(cs);
		//cs.lock();
		for (size_t i = 0; i < 100000; i++)
		{
			val++;
		}
		//cs.unlock();
	};

	std::thread t1(fun);
	std::thread t2(fun);
	std::thread t3(fun);

	t1.join();
	t2.join();
	t3.join();

	std::cout << val << std::endl;
}