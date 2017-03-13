#include "Material.h"
#include <string.h>
#pragma once

Material create_material(char name[], char supplier[], int quantity, ExpDate exp_date)
{
	Material m1;
	strcpy(m1.name, name);
	strcpy(m1.supplier,supplier);
	m1.quantity = quantity;
	m1.exp_date = exp_date;
	return m1;
}

ExpDate assemble_date(int day, int month, int year)
{
	ExpDate new_date;
	new_date.day = day;
	new_date.month = month;
	new_date.year = year;
	return new_date;
}

int eq_date(ExpDate date1, ExpDate date2)
{
	if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year)
		return 1;
	return 0;
}
