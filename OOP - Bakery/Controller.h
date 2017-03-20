#pragma once
#include "Repository.h"

typedef struct BakeryController {
	MaterialRepository *material_repository;
} BakeryController;

/// <summary>
/// Creates a bakery controller
/// </summary>
/// <param name = "material_repository">Pointer to the repo the controller will use</param>
/// <returns>A BakeryController structure</returns>
BakeryController create_controller(MaterialRepository*);

/// <summary>
/// Assembles a material structure and sends it to the repo to be added
/// </summary>
/// <param name = "bakery_controller">Pointer to the bakery controller which should handle the operation</param>
/// <param name = "name">String containing name of material</param>
/// <param name = "supplier">String containing supplier for material</param>
/// <param name = "quantity">An integer number representing quantity of material</param>
/// <param name = "day">An integer number representing day of expiration</param>
/// <param name = "month">An integer number representing month of expiration</param>
/// <param name = "year">An integer number representing year of expiration</param>
/// <returns>An intereger - error code of repo adding function</returns>
int add_material_ctrl(BakeryController*, char name[], char supplier[], int quantity, int day, int month, int year);

/// <summary>
/// Assembles a material structure and sends it to the repo to be deleted
/// </summary>
/// <param name = "bakery_controller">Pointer to the bakery controller which should handle the operation</param>
/// <param name = "name">String containing name of material</param>
/// <param name = "supplier">String containing supplier for material</param>
/// <param name = "day">An integer number representing day of expiration</param>
/// <param name = "month">An integer number representing month of expiration</param>
/// <param name = "year">An integer number representing year of expiration</param>
/// <returns>An intereger - error code of repo adding function</returns>
int delete_material_ctrl(BakeryController*, char name[], char supplier[], int day, int month, int year);

/// <summary>
/// Assembles two material structure and sends then to the repo for updating
/// </summary>
/// <param name = "bakery_controller">Pointer to the bakery controller which should handle the operation</param>
/// <param name = "name">String containing name of existent material</param>
/// <param name = "supplier">String containing supplier for existent material</param>
/// <param name = "day">An integer number representing day of expiration of existent material</param>
/// <param name = "month">An integer number representing month of expiration of existent material</param>
/// <param name = "year">An integer number representing year of expiration of existent material</param>
/// <param name = "new_name">String containing name of new material</param>
/// <param name = "new_supplier">String containing supplier for newmaterial</param>
/// <param name = "new_quantity">An integer number representing new quantity of material</param>
/// <param name = "new_day">An integer number representing day of expiration of new material</param>
/// <param name = "new_month">An integer number representing month of expirationof new material</param>
/// <param name = "new_year">An integer number representing year of expirationof new material</param>
/// <returns>An intereger - error code of repo adding function</returns>
int update_material_ctrl(BakeryController*, char name[], char supplier[], int day, int month, int year, char new_name[], char new_supplier[], int quantity, int new_day, int new_month, int new_year);

/// <summary>
/// Gets in the pos_array all the indexes of expired materials.
/// </summary>
/// <param name = "bakery_controller">Pointer to the controller which should handle the operation</param>
/// <param name = "pos_array">The array where the indexes will be stored</param>
/// <param name = "length">Pointer to the length of the pos_array</param>
void get_expired_materials(BakeryController*, int pos_array[], int* length);

/// <summary>
/// Filters the array of indexes of those who do not contain the given string
/// </summary>
/// <param name = "bakery_controller">Pointer to the controller which should handle the operation</param>
/// <param name = "pos_array">The array where the indexes will be stored</param>
/// <param name = "length">Pointer to the length of the pos_array</param>
/// <param name = "str">The string which must be contained</param>
void filter_expired_str(BakeryController*, int pos_array[], int* length, char str[]);