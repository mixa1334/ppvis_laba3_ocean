#pragma once
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <iostream>
#include <string>
using std::runtime_error;
using std::string;
using std::to_string;
using std::cerr;

namespace ocean
{
	class CantAddToField :public runtime_error
	{
	public:
		CantAddToField(const string& error)
			:runtime_error(error)
		{}
	};

	class CantCreateField :public runtime_error
	{
	public:
		CantCreateField(const string& error)
			:runtime_error(error)
		{}
	};

	class IncorrectlyEnteredData :public runtime_error
	{
	public:
		IncorrectlyEnteredData(const string& error)
			:runtime_error(error)
		{}
	};

	class NoFile :public runtime_error
	{
	public:
		NoFile(const string& path)
			:runtime_error(("Такого файла нет: " + path))
		{}
	};
}

#endif // !EXCEPTIONS_H