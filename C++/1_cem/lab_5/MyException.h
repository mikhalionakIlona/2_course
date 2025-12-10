#pragma once
#include <iostream>
#include <string>
#include <exception>

class MyException : public std::exception
{
protected:
	int code;
	std::string str;
public:
	MyException(std::string& errstr, int errcode)
	{
		str = errstr;
		code = errcode;
	}
	MyException(const MyException& other)
	{
		str = other.str;
		code = other.code;
	}
	~MyException() {};
	const char* what() const noexcept override
	{
		return str.c_str();
	}
	int getCode()
	{
		return code;
	}
};