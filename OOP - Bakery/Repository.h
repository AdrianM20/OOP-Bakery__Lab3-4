#pragma once
#include "Material.h"

typedef struct MaterialRepository {
	Material materials[100];
	int length;
} MaterialRepository;

MaterialRepository create_repository();

int find_material(MaterialRepository *, Material);

int add_material_repo(MaterialRepository*, Material);

int delete_material_repo(MaterialRepository*, Material);

int update_material_repo(MaterialRepository*, Material, Material);