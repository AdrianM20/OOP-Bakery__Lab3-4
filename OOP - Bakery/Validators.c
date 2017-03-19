#include "Validators.h"

void months_vector(int months[13], int year)
{
	months[1] = 31;
	if (year % 4 == 0)
		months[2] = 29;
	else
		months[2] = 28;
	months[3] = 31;
	months[4] = 30;
	months[5] = 31;
	months[6] = 30;
	months[7] = 31;
	months[8] = 31;
	months[9] = 30;
	months[10] = 31;
	months[11] = 30;
	months[12] = 31;
}

int valid_date(ExpDate exp_date)
{
	int months[13];
	months_vector(months, exp_date.year);
	if (exp_date.month < 1 || exp_date.month>12)
		return 0;
	if (exp_date.day < 1 || exp_date.day > months[exp_date.month])
		return 0;
	if (exp_date.year < 2010 || exp_date.year > 2030)
		return 0;
	return 1;
}

int valid_names(char name[], char supplier[])
{
	if (strlen(name) < 3)
		return 0;
	if (strlen(supplier) < 3)
		return 0;
	return 1;
}

int valid_quantity(int quantity)
{
	if (quantity < 1)
		return 0;
	return 1;
}

int validate_material(Material material)
{
	if (valid_names(material.name, material.supplier) == 0)
		return 1;
	if (valid_quantity(material.quantity) == 0)
		return 2;
	if (valid_date(material.exp_date) == 0)
		return 3;
	return 0;
}
