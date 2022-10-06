#include "Singleton.h"

Singleton* Singleton::instance{ nullptr };
std::mutex Singleton::mutex_;

Singleton::Singleton(const std::string& val) : value(val)
{
}

Singleton::~Singleton()
{
	delete instance;
}

Singleton* Singleton::GetInstance(const std::string& value)
{
	std::lock_guard<std::mutex> lock(mutex_);
	if (instance == nullptr)
	{
		instance = new Singleton(value);
	}
	return instance;
}

const std::string& Singleton::getValue() const
{
	return value;
}
