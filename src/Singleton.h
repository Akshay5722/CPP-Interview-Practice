#pragma once

#include <mutex>

class singleton
{
private:

	static singleton* m_instance;
	static std::once_flag onceflag;
	singleton() {}

	singleton* initInstance()
	{
		if (m_instance == nullptr)
			m_instance = new singleton();
		return m_instance;
	}

public:

	~singleton()
	{
		if (m_instance != nullptr)
			delete m_instance;
	}
	
	static singleton* GetInstance()
	{
		std::call_once(onceflag, &singleton::initInstance);
		return m_instance;
	}

	singleton(const singleton&) = delete;
	singleton& operator = (const singleton&) = delete;
};

singleton* singleton::m_instance = nullptr;
std::once_flag singleton::onceflag;