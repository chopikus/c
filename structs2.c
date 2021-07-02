#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_PASSENGERS 8

struct passenger {
	char *name;
	bool is_covid_vaccinated;
};

struct spaceship {
	char* manufacturer;
	struct passenger passengers[MAX_PASSENGERS];
};

int main()
{
	struct spaceship ship = {
		.manufacturer = "SpaceX",	
		.passengers = {
			[0].name = "John Smith",
			[0].is_covid_vaccinated = true,
			[7].name = "Ihor Chovpan",
			[7].is_covid_vaccinated = false
		}
	};
	for (int i=0; i<MAX_PASSENGERS; i++)
	{
		if (ship.passengers[i].name)
			printf("dear passenger named %s, is %svaccinated\n", ship.passengers[i].name, ship.passengers[i].is_covid_vaccinated?"":"not ");
	}
	return 0;
}
