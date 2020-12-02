#pragma once
#ifndef OCEAN_H
#define OCEAN_H
#include "exceptions.h"
#include <vector>
using std::cout;
using std::endl;
using std::vector;

namespace ocean
{

	class OceanOrganism
	{
	public:
		OceanOrganism() = default;

		virtual ~OceanOrganism() = default;

		virtual void print()const = 0;

		virtual string getName()const = 0;

		virtual int getHp()const = 0;

		virtual string getGender()const = 0;

		virtual bool getLifeCycleCeck()const = 0;

		virtual int getPositionX()const = 0;

		virtual int getPositionY()const = 0;

		virtual int getPositionZ()const = 0;

		virtual bool isAlive()const = 0;

		virtual void move() = 0;

		virtual void eat() = 0;

		virtual void attack(const int& damage) = 0;

		virtual void reproduction() = 0;

		virtual void setPositionX(const int& positionX) = 0;

		virtual void setPositionY(const int& positionY) = 0;

		virtual void setPositionZ(const int& positionZ) = 0;

		virtual void setLifeCycleCheck(const bool& cycle) = 0;

	protected:
		virtual void aging() = 0;

	};
}


#endif // !OCEAN_H