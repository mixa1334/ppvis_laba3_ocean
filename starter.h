#pragma once
#ifndef STARTER_H
#define STARTER_H

#include "ocean.h"
#include "exceptions.h"
#include "organism.h"
#include "mackeral.h"
#include "field.h"
#include "seaweed.h"
#include "life.h"
#include "shark.h"
#include "loadFieldFromFile.h"

namespace ocean
{
	class Starter
	{
	public:

		static void start(const string& nameOfFile,const int& cycles);

		static void start();

	};
}

#endif // !STARTER_H