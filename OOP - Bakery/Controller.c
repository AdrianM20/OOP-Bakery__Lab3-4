#include "Controller.h"
#include <string.h>
#include <Windows.h>
#include <assert.h>

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

void get_expired_materials(BakeryController* bakery_controller, int pos_array[], int* length)
{
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	for (int i = 0; i < bakery_controller->material_repository->length; i++) {
		ExpDate exp_date = bakery_controller->material_repository->materials[i].exp_date;
		if (exp_date.year < str_t.wYear) {
			(*length)++;
			pos_array[(*length) - 1] = i;
		}
		else
			if (exp_date.year == str_t.wYear) {
				if (exp_date.month < str_t.wMonth) {
					(*length)++;
					pos_array[(*length) - 1] = i;
				}
				else
					if (exp_date.month == str_t.wMonth) {
						if (exp_date.day < str_t.wDay) {
							(*length)++;
							pos_array[(*length) - 1] = i;
						}
					}
			}
	}
}

void shift_array_left(int some_array[], int pos, int *len)
{
	for (int i = pos; i < (*len); i++)
		some_array[i] = some_array[i + 1];
	(*len)--;
}

void filter_expired_str(BakeryController* bakery_controller, int pos_array[], int* length, char str[])
{
	char* ret;
	char material_name[30];

	get_expired_materials(bakery_controller, pos_array, length);
	
	if (strcmp(str, "") != 0) {
		int i = 0;
		while (i < (*length)) {
			strcpy(material_name, bakery_controller->material_repository->materials[pos_array[i]].name);
			ret = strstr(material_name, str);
			if (ret == NULL)
				shift_array_left(pos_array, i, length);
			else
				i++;
		}
	}
}

void sort_supplier_materials(BakeryController *bakery_controller, Material materials_array[], int *length)
{
	Material aux;
	for (int i = 0; i < bakery_controller->material_repository->length-1; i++) {
		for (int j = i + 1; j < bakery_controller->material_repository->length; j++) {
			char *name1 = bakery_controller->material_repository->materials[i].name;
			char *name2 = bakery_controller->material_repository->materials[j].name;
			if (strcmp(name1, name2) > 0) {
				aux = bakery_controller->material_repository->materials[i];
				bakery_controller->material_repository->materials[i] = bakery_controller->material_repository->materials[j];
				bakery_controller->material_repository->materials[j] = aux;
			}
		}
	}
}

void get_supplier_materials(BakeryController *bakery_controller, Material materials_array[], int * length, char supplier[])
{
	for (int i = 0; i < bakery_controller->material_repository->length; i++) {
		if (strcmp(bakery_controller->material_repository->materials[i].supplier, supplier) == 0) {
			(*length)++;
			materials_array[(*length) - 1] = bakery_controller->material_repository->materials[i];
		}
	}
	sort_supplier_materials(bakery_controller, materials_array, length);
}


// ------------------Tests---------------- //

void init_ctrl_test(MaterialRepository* mr)
{
	ExpDate exp_date = assemble_date(18, 8, 2017);
	Material new_material = create_material("Flour", "Grainz", 20, exp_date);
	add_material_repo(mr, new_material);
	ExpDate expd = assemble_date(22, 9, 2017);
	Material m = create_material("Rice", "Panemar", 45, expd);
	add_material_repo(mr, m);
}

void test_add_ctrl()
{
	MaterialRepository mr = create_repository();
	init_ctrl_test(&mr);
	BakeryController bc = create_controller(&mr);
	assert(bc.material_repository->length == 2);

	assert(add_material_ctrl(&bc, "White Flour", "Grainz co", 125, 22, 9, 2017) == 0);
	assert(bc.material_repository->length == 3);
}

void test_delete_ctrl()
{
	MaterialRepository mr = create_repository();
	init_ctrl_test(&mr);
	BakeryController bc = create_controller(&mr);
	assert(bc.material_repository->length == 2);
	
	add_material_ctrl(&bc, "White Flour", "Grainz co", 125, 22, 9, 2017);
	assert(delete_material_ctrl(&bc, "White Flour", "Grainz co", 22, 9, 2017) == 0);
	assert(bc.material_repository->length == 2);

}

void test_update_ctrl()
{
	MaterialRepository mr = create_repository();
	init_ctrl_test(&mr);
	BakeryController bc = create_controller(&mr);
	assert(bc.material_repository->length == 2);

	//assert(update_material_ctrl(&bc, "Rice", "Panemar", 22, 9, 2017, "Canola", "\n", 84, 0, 0, 0, ) == 0);
	assert(bc.material_repository->length == 2);
}

void test_bakery_controller()
{
	test_add_ctrl();
	test_delete_ctrl();
}
