#include "Repository.h"
#include "Validators.h"

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
	/*if (find_material(material_repository, material) == -1)
		if (validate_material(material) == 0) {
			material_repository->materials[material_repository->length++] = material;
			return 0;
		}
		else
			return validate_material(material);
	else
		if (validate_material(material) == 0) {
			int poz = find_material(material_repository, material);
			material_repository->materials[poz].quantity += material.quantity;
			return 0;
		}
		else
			return validate_material(material);	*/

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
