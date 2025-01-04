#pragma once

class ThreadingOperations
{

public:

	void operator()(const int& a);
	
	int Function(const int& a, const int& b);
	
	static int statFunction(int& a, const int& b);
};

void FreeBuzzGameFun();
void fizzbuzzGameInOtherThread();

void LaunchingTheThreadsUsingDifferentFunctions();