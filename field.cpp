#include "field.h"

ocean::Field::Field(const int& sizeX, const int& sizeY, const string& operatingMode)
{
	if (sizeX <= 0 || sizeY <= 0 || sizeX > 15 || sizeY > 15)
		throw CantCreateField("Невозмжно создать поле размером - [" + to_string(sizeX) + "][" + to_string(sizeY) + "]");

	setOperatingMode(operatingMode);

	field.resize(sizeX);
	for (auto& fy : field)
	{
		fy.resize(sizeY);
	}
}

void ocean::Field::printField() const
{
	for (auto& fx : field)
	{
		for (auto& fy : fx)
		{
			fy.printFisrtPartOfCell();
			cout << "\t";
		}
		cout << "\n";
		for (auto& fy : fx)
		{
			fy.printSecondPartOfCell();
			cout << "\t";
		}
		cout << "\n\n";
	}
}

bool ocean::Field::moveOrganismFromTo(int& fromX, int& fromY,const int& fromZ, const int& toX, const int& toY)
{
	if (!isCorrectPosition(toX, toY))return false;
	if (!field[toX][toY].isFree())return false;

	field[toX][toY].moveOrganismFromOtherCell(&field[fromX][fromY], fromZ);
	fromX = toX;
	fromY = toY;
	return true;
}

bool ocean::Field::isCorrectPosition(const int& positionX, const int& positionY) const
{
	if (positionX >= field.size() || positionX < 0 || positionY >= field[field.size() - 1].size()
		|| positionY < 0) return false;

	return true;
}

ocean::Cell* const ocean::Field::getCell(const int& positionX, const int& positionY)
{
	if (!isCorrectPosition(positionX, positionY))
		return nullptr;

	return &field[positionX][positionY];
}

void ocean::Field::setOperatingMode(const string& operatingMode)
{
	if (operatingMode != "auto" && operatingMode != "step_by_step")
		throw CantCreateField("Неверный режим работы - \"" + operatingMode + "\"" + " -> !only \"auto\" or \"step_by_step\"");

	this->operatingMode = operatingMode;
}

string ocean::Field::getOperatingMode() const
{
	return operatingMode;
}

bool ocean::Field::moveOrganismFromTo(int& fromX, int& fromY, const int& fromZ, const int& toX, const int& toY, const int& toZ)
{
	if (!isCorrectPosition(toX, toY))return false;
	if (!field[toX][toY].isFree(toZ))return false;

	field[toX][toY].moveOrganismFromOtherCell(&field[fromX][fromY], fromZ, toZ);
	fromX = toX;
	fromY = toY;
	return true;
}