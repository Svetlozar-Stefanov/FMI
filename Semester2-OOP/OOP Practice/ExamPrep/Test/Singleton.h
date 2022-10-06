#pragma once
#include <mutex>
class Singleton
{
private:
	static Singleton* instance;
	static std::mutex mutex_;

protected:
	Singleton(const std::string& val);
	~Singleton();
	std::string value;

public:
	Singleton(const Singleton&) = delete;

	void operator=(const Singleton&) = delete;

	static Singleton* GetInstance(const std::string& value);

	const std::string& getValue() const;
};

