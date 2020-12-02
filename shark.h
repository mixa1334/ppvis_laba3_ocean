#pragma once
#ifndef SHARK_H
#define SHARK_H
#include "organism.h"

namespace ocean
{
	class Shark :public Organism
	{
	public:
		Shark(Field* field);

		Shark(Field* field, const string& gender);

		~Shark()override = default;

		void move()override;

		void eat()override;

		void reproduction()override;

	protected:
		void aging()override;

		bool reproductionCheck;
	};
}


#endif // !SHARCK_H
