#include "starter.h"

#include <time.h>
using namespace ocean;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	Starter::start("ppvis_laba3_ocean/ocean1.txt", 10);

	return 0;
}