#pragma once
#include "MyException.h"

class FileException : public MyException
{
public:
	FileException(std::string str,int errcode):MyException(str,errcode){}
	FileException(const FileException& other):MyException(other){}
	~FileException(){}
};