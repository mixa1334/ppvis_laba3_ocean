#include "cell.h"

ocean::Cell::Cell()
{
	cell.resize(4, nullptr);
}

ocean::Cell::~Cell()
{
	cleanCell();
}

void ocean::Cell::printFisrtPartOfCell() const
{
	for (size_t i = 0; i < 2; i++)
	{
		if (cell[i] == nullptr)cout << "* ";
		else cout << cell[i]->getName() << " ";
	}
}

void ocean::Cell::printSecondPartOfCell() const
{
	for (size_t i = 2; i < 4; i++)
	{
		if (cell[i] == nullptr)cout << "* ";
		else cout << cell[i]->getName() << " ";
	}
}

void ocean::Cell::cleanCell()
{
	for (auto& c : cell)
	{
		delete c;
		c = nullptr;
	}
}

bool ocean::Cell::isFree() const
{
	for (auto& c : cell)
	{
		if (c == nullptr)return true;
	}
	return false;
}

bool ocean::Cell::isCorrectPosition(const int& position) const
{
	if (position < 0 || position >= 4)return false;
	return true;
}

bool ocean::Cell::deleteOrganism(const int& position)
{
	if (!isCorrectPosition(position))return false;
	int temp = position;
	delete cell[position];
	cell[temp] = nullptr;
	return true;
}

ocean::OceanOrganism* const ocean::Cell::getOrganism(const int& position)
{
	if (!isCorrectPosition(position))
		return nullptr;

	return cell[position];
}

int ocean::Cell::doesAnOrganismExist(const string& organismName) const
{
	for (int i = 0; i < cell.size(); i++)
	{
		if (cell[i] == nullptr)continue;
		if (organismName == cell[i]->getName())return i;
	}
	return INT_MIN;
}

int ocean::Cell::doesAnOrganismExist(const string& organismName, const string& gender) const
{
	for (int i = 0; i < cell.size(); i++)
	{
		if (cell[i] == nullptr)continue;
		if (organismName == cell[i]->getName() && gender == cell[i]->getGender())return i;
	}
	return INT_MIN;
}

bool ocean::Cell::isFree(const int& position) const
{
	if (!isCorrectPosition(position))
		return false;

	if (cell[position] == nullptr)return true;
	return false;
}

void ocean::Cell::releasePosition(const int& position)
{
	if (isCorrectPosition(position))
	{
		cell[position] = nullptr;
	}
}

bool ocean::Cell::moveOrganismFromOtherCell(Cell* otherCell, const int& position)
{
	if (!isFree() || !isCorrectPosition(position))
		return false;

	for (int i = 0; i < cell.size(); i++)
	{
		if (cell[i]==nullptr)
		{
			cell[i] = otherCell->cell[position];
			otherCell->releasePosition(position);
			cell[i]->setPositionZ(i);
			return true;
		}
	}
}

int ocean::Cell::addToCell(OceanOrganism* organism)
{
	if (!isFree())
		return INT_MAX;

	for (int i = 0; i < cell.size(); i++)
	{
		if (cell[i] == nullptr)
		{
			cell[i] = organism;
			organism->setPositionZ(i);
			return i;
		}
	}
}

int ocean::Cell::addToCell(OceanOrganism* organism, const int& position)
{
	if (!isFree(position))
		return INT_MAX;

	cell[position] = organism;
	organism->setPositionZ(position);
	return position;
}

bool ocean::Cell::moveOrganismFromOtherCell(Cell* otherCell, const int& fromPosition, const int& toPosition)
{
	if (!isFree(toPosition) || !isCorrectPosition(fromPosition));

	cell[toPosition] = otherCell->cell[fromPosition];
	otherCell->releasePosition(fromPosition);
	cell[toPosition]->setPositionZ(toPosition);
	return true;
}