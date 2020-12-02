#include "loadFieldFromFile.h"

ocean::Field* ocean::LoadFieldFromFile::loadField(const string& nameOfFile)
{
	int X;
	int Y;
	string operatingMode;

	fstream file;
	file.open(nameOfFile, fstream::in);

	if (!file.is_open())
		throw NoFile(nameOfFile);

	file >> operatingMode;
	file >> X;
	file >> Y;

	Field* newField = new Field(X, Y, operatingMode);

	for (int i = 0; i < X; i++)
	{
		for (int k = 0; k < Y; k++)
		{
			for (int l = 0; l < 4; l++)
			{
				file >> operatingMode;
				if (operatingMode != "!" && operatingMode != "<<" && operatingMode != "o<") continue;

				OceanOrganism* temp = nullptr;
				if (operatingMode == "!") temp = new Seaweed(newField);
				else if (operatingMode == "o<")	temp = new Mackeral(newField);
				else if (operatingMode == "<<") temp = new Shark(newField);

				temp->setPositionX(i);
				temp->setPositionY(k);
				newField->getCell(i, k)->addToCell(temp);
				operatingMode = "*";
			}
		}
	}

	file.close();
	return newField;
}