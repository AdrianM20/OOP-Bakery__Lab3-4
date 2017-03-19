#include "Material.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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

void material_to_string(Material material, char str[])
{
	sprintf(str, "Material: %s || Supplier: %s || Expires on: %d/%d/%d || Quantity left: %d", material.name, material.supplier, material.exp_date.day, material.exp_date.month, material.exp_date.year, material.quantity);
}
