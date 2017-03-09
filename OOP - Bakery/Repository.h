#pragma once
#include "Material.h"

typedef struct MaterialRepository {
	Material materials[100];
	int length;
} MaterialRepository;

MaterialRepository create_repository();

void add_material_repo(MaterialRepository*, Material);