#pragma once
#include "Repository.h"

typedef struct BakeryController {
	MaterialRepository *material_repository;
} BakeryController;

BakeryController create_controller(MaterialRepository*);

void add_material_ctrl(BakeryController *bakery_controller, char name[], char supplier[], int quantity, ExpDate exp_date);