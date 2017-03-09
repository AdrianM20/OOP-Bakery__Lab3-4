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
