#pragma once

typedef struct ExpDate {
	int year;
	int month;
	int day;
} ExpDate;

typedef struct Material {
	char name[30];
	char supplier[50];
	int quantity;
	ExpDate exp_date;
} Material;


Material create_material(char name[], char supplier[], int quantity, ExpDate exp_date);
