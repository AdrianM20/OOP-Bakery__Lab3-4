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

ExpDate assemble_date(int day, int month, int year);

int eq_date(ExpDate date1, ExpDate date2);

char material_to_string(Material, char str[]);