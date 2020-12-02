#include "organism.h"

ocean::Organism::Organism(const string& name, Field* field, const string& gender)
	:OceanOrganism(), hp(100), field(field), name(name), gender(gender),lifeCycle(false)
{}

ocean::Organism::Organism(const string& name, Field* field)
	: OceanOrganism(), hp(100), field(field), name(name),lifeCycle(false)
{
	int key = rand() % 2;

	switch (key)
	{
	case 0:
		this->gender = "man";
		break;
	case 1:
		this->gender = "woman";
		break;
	}
}

bool ocean::Organism::isAlive()const
{
	if (hp > 0)return true;
	return false;
}

void ocean::Organism::print() const
{
	cout << name << " ";
}

string ocean::Organism::getName() const
{
	return name;
}

int ocean::Organism::getHp() const
{
	return hp;
}

string ocean::Organism::getGender() const
{
	return gender;
}

void ocean::Organism::attack(const int& damage)
{
	hp -= damage;

	if (!isAlive())
		field->getCell(positionX,positionY)->deleteOrganism(positionZ);
}

void ocean::Organism::setPositionX(const int& positionX)
{
	this->positionX = positionX;
}

void ocean::Organism::setPositionY(const int& positionY)
{
	this->positionY = positionY;
}

void ocean::Organism::setPositionZ(const int& positionZ)
{
	this->positionZ = positionZ;
}

void ocean::Organism::setLifeCycleCheck(const bool& cycle)
{
	this->lifeCycle = cycle;
}

bool ocean::Organism::getLifeCycleCeck() const
{
	return lifeCycle;
}

int ocean::Organism::getPositionX() const
{
	return positionX;
}

int ocean::Organism::getPositionY() const
{
	return positionY;
}

int ocean::Organism::getPositionZ() const
{
	return positionZ;
}