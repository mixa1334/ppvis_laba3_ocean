#include "mackeral.h"

ocean::Mackeral::Mackeral(Field* field)
	:Organism("o<", field)
{}

ocean::Mackeral::Mackeral(Field* field, const string& gender)
	: Organism("o<", field, gender)
{}

void ocean::Mackeral::move()
{
	int toX = positionX;
	int toY = positionY;

	Movement move = static_cast<Movement>(rand() % 4);

	for (size_t i = 0; i < 4; i++)
	{
		switch (move)
		{
		case Movement::up:
			toX += 1;
			move = Movement::down;
			break;
		case Movement::down:
			toX -= 1;
			move = Movement::right;
			break;
		case Movement::right:
			toY += 1;
			move = Movement::left;
			break;
		case Movement::left:
			toY -= 1;
			move = Movement::up;
			break;
		}
		if (field->moveOrganismFromTo(positionX, positionY, positionZ, toX, toY))
			break;

		toX = positionX;
		toY = positionY;
	}

	lifeCycle = true;
	aging();
}

void ocean::Mackeral::aging()
{
	hp -= 10;

	if (!isAlive())
		field->getCell(positionX,positionY)->deleteOrganism(positionZ);
}

void ocean::Mackeral::eat()
{
	int toZ = field->getCell(positionX,positionY)->doesAnOrganismExist("!");

	if (field->getCell(positionX,positionY)->isCorrectPosition(toZ))
	{
		field->getCell(positionX,positionY)->getOrganism(toZ)->attack(200);
		field->moveOrganismFromTo(positionX, positionY, positionZ, positionX, positionY, toZ);
		hp += 15;
	}
	else hp -= 10;

	lifeCycle = true;
	if (!isAlive())
		field->getCell(positionX, positionY)->deleteOrganism(positionZ);
}

void ocean::Mackeral::reproduction()
{
	if (field->getCell(positionX,positionY)->isFree())
	{
		int tempPositionZ;
		if (this->getGender() == "man")	tempPositionZ = field->getCell(positionX,positionY)->doesAnOrganismExist(this->getName(), "woman");
		else if (this->getGender() == "woman") tempPositionZ = field->getCell(positionX,positionY)->doesAnOrganismExist(this->getName(), "man");

		if (field->getCell(positionX,positionY)->isCorrectPosition(tempPositionZ))
		{
			field->getCell(positionX,positionY)->getOrganism(tempPositionZ)->setLifeCycleCheck(true);

			OceanOrganism* temp = new Mackeral(field);
			temp->setPositionX(positionX);
			temp->setPositionY(positionY);
			temp->setPositionZ(positionZ);
			tempPositionZ = field->getCell(positionX, positionY)->addToCell(temp);
		}
	}
	lifeCycle = true;
}