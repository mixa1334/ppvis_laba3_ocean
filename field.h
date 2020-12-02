#pragma once
#ifndef FIELD_H
#define FIELD_H
#include "ocean.h"
#include "cell.h"

namespace ocean
{

	class Life;

	class Field
	{
	public:
		Field(const int& sizeX = 5, const int& sizeY = 5, const string& operationMode = "auto");

		void setOperatingMode(const string& operatingMode);

		string getOperatingMode()const;

		void printField()const;

		bool moveOrganismFromTo(int& fromX, int& fromY, const int& fromZ, const int& toX, const int& toY);

		bool moveOrganismFromTo(int& fromX, int& fromY, const int& fromZ, const int& toX, const int& toY, const int& toZ);

		bool isCorrectPosition(const int& positionX, const int& positionY)const;

		Cell* const getCell(const int& positionX, const int& positionY);

	private:
		vector<vector<Cell>> field;

		string operatingMode;

		friend class Life;
	};
}

#endif // !FIELD_H