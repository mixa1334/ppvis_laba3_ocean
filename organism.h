#pragma once
#ifndef ORGANISM_H
#define ORGANISM_H
#include "ocean.h"
#include "field.h"


namespace ocean
{
	class Organism :public OceanOrganism
	{
	public:
		Organism(const string& name, Field* field, const string& gender);

		Organism(const string& name, Field* field);

		~Organism()override = default;

		void print()const override final;

		string getName()const override final;

		int getHp()const override final;

		bool getLifeCycleCeck()const override;

		int getPositionX()const override;

		int getPositionY()const override;

		int getPositionZ()const override;

		void setPositionX(const int& positionX)override final;

		void setPositionY(const int& positionY)override final;

		void setPositionZ(const int& positionZ)override final;

		void setLifeCycleCheck(const bool& cycle)override final;

		virtual string getGender()const override final;

		void move()override = 0;

		void eat()override = 0;

		virtual void reproduction() = 0;

		bool isAlive()const override final;

		virtual void attack(const int& damage) override final;

	protected:
		int positionX;
		int positionY;
		int positionZ;
		bool lifeCycle;
		int hp;

		Field* const field;

		enum class Movement
		{
			up = 0,
			down = 1,
			right = 2,
			left = 3,
		};

		void aging()override = 0;

	private:
		string gender;

		string name;
	};

}
#endif // !ORGANISM_H