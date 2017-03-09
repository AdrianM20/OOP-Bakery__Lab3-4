#include "Repository.h"

MaterialRepository create_repository()
{
	MaterialRepository new_repository;
	new_repository.length = 0;
	return new_repository;
}

void add_material_repo(MaterialRepository *material_repository, Material material)
{
	material_repository->materials[material_repository->length++] = material;
}
