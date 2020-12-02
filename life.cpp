#include "life.h"

void ocean::Life::life(const int& number, Field* field)
{
	if (number <= 0)
		throw IncorrectlyEnteredData(" ол-во циклов жизни не может быть меньше 1: " + to_string(number));

	system("cls");
	cout << "Field:" << "\n\n";
	field->printField();
	if (field->operatingMode == "step_by_step")system("pause");
	else Sleep(500);
	system("cls");

	for (size_t i = 1; i <= number; i++)
	{
		cout << "Move:" << "\n\n";
		cycle(Operations::move, field);
		field->printField();
		if (field->operatingMode == "step_by_step")system("pause");
		else Sleep(500);
		system("cls");

		cout << "Eat:" << "\n\n";
		cycle(Operations::eat, field);
		field->printField();
		if (field->operatingMode == "step_by_step")system("pause");
		else Sleep(500);
		system("cls");

		cout << "Reproduction:" << "\n\n";
		cycle(Operations::reproduction, field);
		field->printField();
		if (field->operatingMode == "step_by_step")system("pause");
		else Sleep(500);
		system("cls");
	}

}

void ocean::Life::cycle(const Operations& op, Field* field)
{
	for (int i = 0; i < field->field.size(); i++)
	{
		for (int k = 0; k < field->field[i].size(); k++)
		{
			Cell* temp = &field->field[i][k];
			for (int l = 0; l < 4; l++)
			{
				OceanOrganism* tempOrganism = temp->getOrganism(l);
				if (tempOrganism == nullptr)continue;
				if (tempOrganism->getLifeCycleCeck() && op != Operations::resetCycle)continue;

				switch (op)
				{
				case Operations::move:
					tempOrganism->move();
					break;
				case Operations::eat:
					tempOrganism->eat();
					break;
				case Operations::reproduction:
					tempOrganism->reproduction();
					break;
				case Operations::resetCycle:
					tempOrganism->setLifeCycleCheck(false);
					break;
				default:
					break;
				}
			}
		}
	}
	if (op != Operations::resetCycle) cycle(Operations::resetCycle, field);
}