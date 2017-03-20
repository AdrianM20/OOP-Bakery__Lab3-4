#include "Repository.h"
#include "Validators.h"
#include <assert.h>

MaterialRepository create_repository()
{
	MaterialRepository new_repository;
	new_repository.length = 0;
	return new_repository;
}

int find_material(MaterialRepository *material_repository, Material material)
{
	for (int i = 0; i < material_repository->length; i++) {
		char *name = material_repository->materials[i].name;
		char *supplier = material_repository->materials[i].supplier;
		ExpDate exp_date = material_repository->materials[i].exp_date;
		if (strcmp(name,material.name) == 0 && strcmp(supplier, material.supplier) == 0 && eq_date(exp_date, material.exp_date) == 1)
			return i;
	}
	return -1;
}

int add_material_repo(MaterialRepository *material_repository, Material material)
{
	if (validate_material(material) == 0) {
		if (find_material(material_repository, material) == -1) {
			material_repository->materials[material_repository->length++] = material;
			return 0;
		}
		else {
			int poz = find_material(material_repository, material);
			material_repository->materials[poz].quantity += material.quantity;
			return 0;
		}
	}
	else
		return validate_material(material);
}

void shift_repo_left(MaterialRepository *material_repository, int position)
{
	for (int i = position; i < material_repository->length; i++)
		material_repository->materials[i] = material_repository->materials[i + 1];
	material_repository->length -= 1;
}

int delete_material_repo(MaterialRepository *material_repository, Material material)
{
	if (validate_material(material) == 0) {
		if (find_material(material_repository, material) == -1)
			return 4;
		else
		{
			int poz = find_material(material_repository, material);
			shift_repo_left(material_repository, poz);
			return 0;
		}
	}
	return validate_material(material);
}

int update_material_repo(MaterialRepository *material_repository, Material old_material, Material new_material)
{
	if (find_material(material_repository, old_material) == -1)
		return 4;
	else {
		int poz = find_material(material_repository, old_material);
		if (new_material.quantity == 0) {
			new_material.quantity = material_repository->materials[poz].quantity;
			if (validate_material(new_material) == 0) {
				material_repository->materials[poz] = new_material;
				return 0;
			}
			else
				return validate_material(new_material);
		}
		else {
			if (validate_material(new_material) == 0) {
				material_repository->materials[poz] = new_material;
				return 0;
			}
			else
				return validate_material(new_material);
		}
	}
}


//-----------------Tests------------------------//

void init_repo_test(MaterialRepository* mr)
{
	ExpDate exp_date = assemble_date(18, 8, 2017);
	Material new_material = create_material("Flour", "Grainz", 20, exp_date);
	add_material_repo(mr, new_material);
}

void test_add()
{
	ExpDate expd = assemble_date(22, 9, 2017);
	Material m = create_material("Rice", "Panemar", 45, expd);

	MaterialRepository mr = create_repository();
	init_repo_test(&mr);
	assert(mr.length == 1);

	assert(add_material_repo(&mr, m) == 0);
	assert(mr.length == 2);
}

void test_delete()
{
	ExpDate expd1 = assemble_date(22, 9, 2018);
	Material m1 = create_material("Rice", "Panemar", 45, expd1);

	MaterialRepository mr = create_repository();
	init_repo_test(&mr);
	add_material_repo(&mr, m1);
	assert(mr.length == 2);

	assert(delete_material_repo(&mr, m1) == 0);
	assert(mr.length == 1);
	assert(delete_material_repo(&mr, m1) == 4);
}

void test_update()
{
	ExpDate expd1 = assemble_date(22, 9, 2018);
	Material m1 = create_material("Rice", "Panemar", 45, expd1);

	MaterialRepository mr = create_repository();
	init_repo_test(&mr);
	add_material_repo(&mr, m1);
	assert(mr.length == 2);

	Material m2 = create_material("Rice", "Grainz", 65, expd1);
	assert(update_material_repo(&mr, m1, m2) == 0);
	assert(strcmp(&mr.materials[find_material(&mr, m2)].supplier,"Grainz") == 0);
}

void test_material_repo()
{
	test_add();
	test_delete();
	test_update();
}
