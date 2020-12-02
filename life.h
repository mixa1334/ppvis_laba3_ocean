#pragma once
#ifndef LIFE_H
#define LIFE_H
#include "field.h"
#include <Windows.h>

namespace ocean
{
	class Life
	{
	public:
		static void life(const int& number, Field* field);

	private:

		enum class Operations
		{
			eat = 1,
			move = 2,
			reproduction = 3,
			resetCycle = 4,
		};

		static void cycle(const Operations& op, Field* field);

	};
}

#endif // !LIFE_H