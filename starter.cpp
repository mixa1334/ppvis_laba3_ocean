#include "starter.h"


void ocean::Starter::start()
{
	Field* field = nullptr;

	try
	{
		string nameOfFile;
		cout << "Введите имя файла - ";
		std::cin >> nameOfFile;

		field = LoadFieldFromFile::loadField(nameOfFile);

		cout << "Введите кол-во циклов жизни, которое необходимо пройти - ";
		int cycles;
		std::cin >> cycles;

		Life::life(cycles, field);

		delete field;
	}
	catch (const runtime_error& ex)
	{
		delete field;
		cerr << endl << ex.what();
	}
}


void ocean::Starter::start(const string& nameOfFile, const int& cycles)
{
	Field* field = nullptr;

	try
	{
		field = LoadFieldFromFile::loadField(nameOfFile);

		Life::life(cycles, field);

		delete field;
	}
	catch (const runtime_error& ex)
	{
		delete field;
		cerr << endl << ex.what();
	}
}