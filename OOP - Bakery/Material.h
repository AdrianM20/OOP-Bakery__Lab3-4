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

/// <summary>
/// Creates a material structure.
/// </summary>
/// <param name = "name">A string containing the name of the material</param>
/// <param name = "supplier">A string containing the name of the supplier</param>
/// <param name = "quantity">An integer number representing the quantity of the material</param>
/// <param name = "exp_date">An ExpDate structure representing the expiration date of the material</param>
/// <returns>A Material structure representing the material</returns>
Material create_material(char name[], char supplier[], int quantity, ExpDate exp_date);

/// <summary>
/// Create an expire date structure.
/// </summary>
/// <param name = "day">An integer number representing the expiration day</param>
/// <param name = "month">An integer number representing the expiration month</param>
/// <param name = "year">An integer number representing the expiration month</param>
/// <returns>A ExpDate structure</returns>
ExpDate assemble_date(int day, int month, int year);

/// <summary>
/// Checks if 2 dates are equal.
/// </summary>
/// <param name = "date1/date2">ExpDate types to be compared</param>
/// <returns>1 if dates are equal, 0 otherwise</returns>
int eq_date(ExpDate, ExpDate);

/// <summary>
/// Creates a string containing the material info.
/// </summary>
/// <param name = "material">The material which is converted to a string</param>
/// <param name = "str">The char array where the string will be stored</param>
void material_to_string(Material, char str[]);