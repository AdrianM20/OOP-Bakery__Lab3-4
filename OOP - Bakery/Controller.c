#include "Controller.h"
#include <string.h>
BakeryController create_controller(MaterialRepository *material_repository)
{
	BakeryController new_controller;
	new_controller.material_repository = material_repository;
	return new_controller;
}

int add_material_ctrl(BakeryController * bakery_controller, char name[], char supplier[], int quantity, int day, int month, int year)
{
	ExpDate exp_date = assemble_date(day, month, year);
	Material new_material = create_material(name, supplier, quantity, exp_date);
	
	int res = 0;
	res = add_material_repo(bakery_controller->material_repository, new_material);
	return res;
}

int delete_material_ctrl(BakeryController * bakery_controller, char name[], char supplier[], int day, int month, int year)
{
	ExpDate exp_date = assemble_date(day, month, year);
	Material new_material = create_material(name, supplier, 1, exp_date);
	
	int res = 0;
	res = delete_material_repo(bakery_controller->material_repository, new_material);
	return res;
}

int update_material_ctrl(BakeryController * bakery_controller, char name[], char supplier[], int day, int month, int year, char new_name[], char new_supplier[], int quantity, int new_day, int new_month, int new_year)
{
	if (strcmp(new_name, "\n") == 0)
		strcpy(new_name, name);
	if (strcmp(new_supplier, "\n") == 0)
		strcpy(new_supplier, supplier);
	if (new_day == 0 || new_month == 0 || new_year == 0) {
		new_day = day;
		new_month = month;
		new_year = year;
	}
	
	ExpDate old_date = assemble_date(day, month, year);
	ExpDate new_date = assemble_date(new_day, new_month, new_year);

	Material old_material = create_material(name, supplier, 1, old_date);
	Material new_material = create_material(new_name, new_supplier, quantity, new_date);

	int res = 0;
	res = update_material_repo(bakery_controller->material_repository, old_material, new_material);
	return res;
}
