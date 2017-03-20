#pragma once
#include "Repository.h"

typedef struct BakeryController {
	MaterialRepository *material_repository;
} BakeryController;

BakeryController create_controller(MaterialRepository*);

int add_material_ctrl(BakeryController*, char name[], char supplier[], int quantity, int day, int month, int year);

int delete_material_ctrl(BakeryController*, char name[], char supplier[], int day, int month, int year);

int update_material_ctrl(BakeryController*, char name[], char supplier[], int day, int month, int year, char new_name[], char new_supplier[], int quantity, int new_day, int new_month, int new_year);

void get_expired_materials(BakeryController*, int pos_array[], int* length);

void filter_expired_str(BakeryController*, int pos_array[], int* length, char str[]);