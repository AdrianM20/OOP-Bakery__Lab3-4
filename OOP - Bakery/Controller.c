#include "Controller.h"

BakeryController create_controller(MaterialRepository *material_repository)
{
	BakeryController new_controller;
	new_controller.material_repository = material_repository;
	return new_controller;
}

void add_material_ctrl(BakeryController * bakery_controller, char name[], char supplier[], int quantity, ExpDate exp_date)
{
	Material new_material = create_material(name, supplier, quantity, exp_date);
	add_material_repo(bakery_controller->material_repository, new_material);
}