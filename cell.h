#pragma once
#ifndef CELL_H
#define CELL_H
#include "ocean.h"

namespace ocean
{
	
	class Cell
	{
	public:
		Cell();

		~Cell();

		void printFisrtPartOfCell()const;

		void printSecondPartOfCell()const;

		void cleanCell();

		int addToCell(OceanOrganism* organism);

		int addToCell(OceanOrganism* organism, const int& position);

		bool isFree()const;

		bool isFree(const int& position)const;

		bool moveOrganismFromOtherCell(Cell* otherCell, const int& fromPosition,const int& toPosition);

		bool moveOrganismFromOtherCell(Cell* otherCell, const int& fromPosition);

		bool isCorrectPosition(const int& position)const;

		bool deleteOrganism(const int& position);

		OceanOrganism* const getOrganism(const int& position);

		int doesAnOrganismExist(const string& organismName, const string& gender)const;

		int doesAnOrganismExist(const string& organismName)const;

	private:
		vector<OceanOrganism*> cell;

		void releasePosition(const int& position);

		friend class Life;
	};
}

#endif // !FIELD_H