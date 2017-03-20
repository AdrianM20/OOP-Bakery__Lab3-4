#pragma once
#include "Material.h"

typedef struct MaterialRepository {
	Material materials[100];
	int length;
} MaterialRepository;

/// <summary>
/// Creates a material repository.
/// </summary>
/// <returns>A MaterialRepostory type structure</returns>
MaterialRepository create_repository();

/// <summary>
/// Searches for the given material in the material repository
/// </summary>
/// <param name = "material_repository">Pointer to the repo where the material should be searched</param>
/// <param name = "material">The material which must be searched</param>
/// <returns> -1 if the material is not found, the index of the material if it is found</returns>
int find_material(MaterialRepository*, Material);

/// <summary>
/// Adds a material to the repostitory.
/// </summary>
/// <param name = "material_repository">Pointer to the repo where the material shoud be added</param>
/// <param name = "material">Material to be added to the repo</param>
/// <returns>0 - if succesful, error code if not succesful</returns>
int add_material_repo(MaterialRepository*, Material);

/// <summary>
/// Deletes a material from the repostitory.
/// </summary>
/// <param name = "material_repository">Pointer to the repo from where the material shoud be deleted</param>
/// <param name = "material">Material to be deleted from the repo</param>
/// <returns>0 - if succesful, error code if not succesful</returns>
int delete_material_repo(MaterialRepository*, Material);

/// <summary>
/// Update a material from the repostitory.
/// </summary>
/// <param name = "material_repository">Pointer to the repo where the material shoud be updated</param>
/// <param name = "material">Material to be updated to the repo</param>
/// <returns>0 - if succesful, error code if not succesful</returns>
int update_material_repo(MaterialRepository*, Material, Material);

void test_material_repo();