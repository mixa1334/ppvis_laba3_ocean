#include "shark.h"

ocean::Shark::Shark(Field* field)
	:Organism("<<", field), reproductionCheck(false)
{}

ocean::Shark::Shark(Field* field, const string& gender)
	: Organism("<<", field, gender), reproductionCheck(false)
{}

void ocean::Shark::aging()
{
	hp -= 5;

	if (!isAlive())
		field->getCell(positionX,positionY)->deleteOrganism(positionZ);
}

void ocean::Shark::reproduction()
{
	if (field->getCell(positionX,positionY)->isFree() && !reproductionCheck)
	{
		int tempPositionZ;
		if (this->getGender() == "man")	tempPositionZ = field->getCell(positionX,positionY)->doesAnOrganismExist(this->getName(), "woman");
		else if (this->getGender() == "woman") tempPositionZ = field->getCell(positionX,positionY)->doesAnOrganismExist(this->getName(), "man");

		if (field->getCell(positionX,positionY)->isCorrectPosition(tempPositionZ))
		{
			field->getCell(positionX,positionY)->getOrganism(tempPositionZ)->setLifeCycleCheck(true);

			OceanOrganism* temp = new Shark(field);
			temp->setPositionX(positionX);
			temp->setPositionY(positionY);
			temp->setLifeCycleCheck(true);
			tempPositionZ = field->getCell(positionX, positionY)->addToCell(temp);
			reproductionCheck = true;
		}
	}
	lifeCycle = true;
}

void ocean::Shark::eat()
{
	int toZ = field->getCell(positionX,positionY)->doesAnOrganismExist("o<");

	if (field->getCell(positionX,positionY)->isCorrectPosition(toZ))
	{
		field->getCell(positionX,positionY)->getOrganism(toZ)->attack(200);
		field->moveOrganismFromTo(positionX, positionY, positionZ, positionX, positionY, toZ);
		hp += 30;
	}
	else hp -= 10;

	lifeCycle = true;
	if (!isAlive())
		field->getCell(positionX, positionY)->deleteOrganism(positionZ);
}

void ocean::Shark::move()
{
	int toX = positionX;
	int toY = positionY;

	Movement move = static_cast<Movement>(rand() % 4);

	for (size_t i = 0; i < 4; i++)
	{
		switch (move)
		{
		case Movement::right:
			toY += rand() % 2 + 1;
			move = Movement::left;
			break;
		case Movement::left:
			toY -= rand() % 2 + 1;
			move = Movement::up;
			break;
		case Movement::up:
			toX += rand() % 2 + 1;
			move = Movement::down;
			break;
		case Movement::down:
			toX -= rand() % 2 + 1;
			move = Movement::right;
			break;
		}
		if (field->moveOrganismFromTo(positionX, positionY, positionZ, toX, toY)) break;
		toX = positionX;
		toY = positionY;
	}

	lifeCycle = true;
	aging();
}