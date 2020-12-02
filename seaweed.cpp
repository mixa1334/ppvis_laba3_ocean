#include "seaweed.h"

ocean::Seaweed::Seaweed(Field* field)
	:Organism("!", field, "no gender")
{}

void ocean::Seaweed::aging()
{
	hp -= 5;

	if (!isAlive())
		field->getCell(positionX, positionY)->deleteOrganism(positionZ);
}

void ocean::Seaweed::reproduction()
{
	if (field->getCell(positionX,positionY)->isFree())
	{
		OceanOrganism* temp = new Seaweed(field);
		temp->setLifeCycleCheck(true);
		temp->setPositionX(positionX);
		temp->setPositionY(positionY);
		int positionZ = field->getCell(positionX, positionY)->addToCell(temp);
		if (!field->getCell(positionX,positionY)->isFree())
		{
			field->getCell(positionX, positionY)->deleteOrganism(positionZ);
		}
	}
}

void ocean::Seaweed::move()
{
	lifeCycle = true;
	aging();
}

void ocean::Seaweed::eat()
{
	lifeCycle = true;
	aging();
}