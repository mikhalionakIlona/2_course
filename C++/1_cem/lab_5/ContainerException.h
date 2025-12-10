#pragma once
#include "MyException.h"

class ContainerException :public MyException
{
public:
	ContainerException(std::string str,int errcode):MyException(str,errcode){}
	ContainerException(const ContainerException& other):MyException(other){}
	~ContainerException() {}
};