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
	if (find_material(material_repository, material) == -1)
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
			return validate_material(material);	
}
