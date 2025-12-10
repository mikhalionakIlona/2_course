#pragma once
#include "MyException.h"

class InputException: public MyException
{
public:
	InputException(std::string str, int errcode):MyException(str,errcode){}
	InputException(const InputException& other):MyException(other){}
	~InputException() {};
};