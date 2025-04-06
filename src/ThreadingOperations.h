#pragma once

#include <thread>

class ThreadingOperations
{

public:

	void operator()(const int& a);
	
	int Function(const int& a, const int& b);
	
	static int statFunction(const int& a, const int& b);
};

class thread_guard 
{
private:
	std::thread m_thrd;

public:
	explicit thread_guard(std::thread&& thrd)
	{
		m_thrd = std::move(thrd);
	}

	~thread_guard()
	{
		if (m_thrd.joinable())
			m_thrd.join();
	}
};

void FreeBuzzGameFun();
void fizzbuzzGameInOtherThread();

void LaunchingTheThreadsUsingDifferentFunctions();

void threadHandleOperation();

void handlethreadException();

void DataRaces();

void DataRacesSolvedUsingCriticalSection();
void DataRacesSolvedUsingMutex();