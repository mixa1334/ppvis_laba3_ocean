#pragma once
#ifndef SEAWEED_H
#define SEAWEED_H
#include "organism.h"


namespace ocean
{
	class Seaweed :public Organism
	{
	public:
		Seaweed(Field* field);

		~Seaweed()override = default;

		void move()override;

		void eat()override;

		void reproduction()override;

	protected:
		void aging()override;
	};
}

#endif // !SEAWEED_H