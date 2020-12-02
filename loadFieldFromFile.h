#pragma once
#ifndef LOADFIELDFROMFILE_H
#define LOADFIELDFROMFILE_H

#include "field.h"

#include "mackeral.h"
#include "seaweed.h"
#include "shark.h"


#include <fstream>
using std::fstream;


namespace ocean
{
	class LoadFieldFromFile
	{
	public:
		static Field* loadField(const string& nameOfFile);
	};
}
#endif // !LOADFIELDFROMFILE_H