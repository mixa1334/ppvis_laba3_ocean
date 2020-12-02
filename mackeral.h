#pragma once
#ifndef MACKERAL_H
#define MACKERAL_H
#include "organism.h"

namespace ocean
{
	class Mackeral :public Organism
	{
	public:
		Mackeral(Field* field);

		Mackeral(Field* field, const string& gender);

		~Mackeral()override = default;

		void move()override;

		void eat()override;

		void reproduction()override;

	protected:
		void aging()override;

	};
}

#endif // !MACKERAL_H