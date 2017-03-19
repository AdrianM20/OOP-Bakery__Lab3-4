#include "UI.h"
#include <stdio.h>
#include <Windows.h>

Console create_console(BakeryController *bakery_controller)
{
	Console new_console;
	new_console.bakery_controller = bakery_controller;
	return new_console;
}

void print_menu()
{
	printf("\n||------------Choose an option---------------||\n");
	printf("|| 1 - Add material                          ||\n");
	printf("|| 2 - Delete material                       ||\n");
	printf("|| 3 - Update material                       ||\n");
	printf("|| 4 - List materials                        ||\n");+
	printf("|| 0 - Exit program                          ||\n");
	printf("||------------Choose an option---------------||\n");
}

int read_integer_number()
{
	char input[12];
	int res;
	int flag = 0;
	int r;

	while (flag == 0) {
		printf("||  Insert option: ");
		scanf("%s", input);
		r = sscanf(input, "%d", &res);
		flag = (r == 1);
		if (flag == 0)
			printf("Error while reading input. Make sure you use only digits.\n");
	}
	return res;
}

int valid_command(int command)
{
	if (command >= 0 && command <= 4)
		return 1;
	return 0;
}

void read_string(char *input, int length)
/* Wannabe read string with whitespaces */
{
	fgets(input, sizeof(char) * length, stdin);
	sscanf(input, "%[^\n]", input);
}

void init_data(Console* console)
{
	int res = 0;
	res = add_material_ctrl(console->bakery_controller, "Flour", "Grainz co", 125, 22, 9, 2017);
	if (res != 0)
		printf("ERROR!\n");
	res = add_material_ctrl(console->bakery_controller, "Rice", "Grainz co", 45, 15, 3, 2018);
	if (res != 0)
		printf("ERROR!\n");
	res = add_material_ctrl(console->bakery_controller, "Wheat", "Old Farm", 85, 29, 2, 2020);
	if (res != 0)
		printf("ERROR!\n");
	res = add_material_ctrl(console->bakery_controller, "Corn", "Old Farm", 28, 15, 4, 2016);
	if (res != 0)
		printf("ERROR!\n");
}

void add_material_ui(Console* console)
{
	char name[30], supplier[50], dump[4];
	int quantity, day, month, year, res;

	gets(dump);
	printf("Insert name of material: ");
	read_string(name, 29);
	//scanf("%29s", name);
	printf("Insert supplier for material: ");
	read_string(supplier, 49);
	//scanf("%49s", supplier);
	printf("Insert quantity: ");
	scanf("%d", &quantity);

	printf("Insert expiration date for material:\n");
	printf("Day: ");
	scanf("%d", &day);
	printf("Month: ");
	scanf("%d", &month);
	printf("Year: ");
	scanf("%d", &year);

	res = add_material_ctrl(console->bakery_controller, name, supplier, quantity, day, month, year);
	
	switch (res)
	{
	case 0:
	{
		printf("Material added succesfully.\n");
		break;
	}
	case 1:
	{
		printf("An error occurred: Name or supplier length must be at least 3. Material not added.\n");
		break;
	}
	case 2:
	{
		printf("An error occurred: Quantity should be at least 1. Material not added.\n");
		break;
	}
	case 3:
	{
		printf("An error occurred: Date format incorrect. Material not added.\n");
		break;
	}
	}
}

void delete_material_ui(Console *console)
{
	char name[30], supplier[50], dump[4];
	int day, month, year, res;

	gets(dump);
	printf("Insert name of material: ");
	//scanf("%29s", name);
	read_string(name, 29);
	printf("Insert supplier for material: ");
	//scanf("%49s", supplier);
	read_string(supplier, 49);

	printf("Insert expiration date for material:\n");
	printf("Day: ");
	scanf("%d", &day);
	printf("Month: ");
	scanf("%d", &month);
	printf("Year: ");
	scanf("%d", &year);

	res = delete_material_ctrl(console->bakery_controller, name, supplier, day, month, year);

	switch (res)
	{
	case 0:
	{
		printf("Material deleted succesfully.\n");
		break;
	}
	case 1:
	{
		printf("An error occurred: Name or supplier length must be at least 3. Nothing was modified.\n");
		break;
	}
	case 2:
	{
		printf("An error occurred: Quantity should be at least 1. Nothing was modified.\n");
		break;
	}
	case 3:
	{
		printf("An error occurred: Date format incorrect. Nothing was modified.\n");
		break;
	}
	case 4:
	{
		printf("An error occured: Material does not exist. Nothing was modified.\n");
		break;
	}
	}
}

void update_material_ui(Console *console)
{
	char name[30], supplier[50], new_name[30], new_supplier[50], dump[4];
	int day, month, year, new_quantity, new_day, new_month, new_year, res;

	gets(dump);
	printf("Insert name of material to update: ");
	read_string(name, 29);
	printf("Insert new name for material: ");
	read_string(new_name, 29);
	printf("Insert name of old supplier: ");
	read_string(supplier, 49);
	printf("Insert name of new supplier: ");
	read_string(new_supplier, 49);

	printf("Insert new quantity: ");
	scanf("%d", &new_quantity);

	printf("Insert old expiration date: \n");
	printf("Day: ");
	scanf("%d", &day);
	printf("Month: ");
	scanf("%d", &month);
	printf("Year: ");
	scanf("%d", &year);

	printf("Insert new expiration date: \n");
	printf("Day: ");
	scanf("%d", &new_day);
	printf("Month: ");
	scanf("%d", &new_month);
	printf("Year: ");
	scanf("%d", &new_year);

	res = update_material_ctrl(console->bakery_controller, name, supplier, day, month, year, new_name, new_supplier, new_quantity, new_day, new_month, new_year);

	switch (res)
	{
	case 0:
	{
		printf("Material updated succesfully.\n");
		break;
	}
	case 1:
	{
		printf("An error occurred: Name or supplier length must be at least 3. Nothing was modified.\n");
		break;
	}
	case 2:
	{
		printf("An error occurred: Quantity should be at least 1. Nothing was modified.\n");
		break;
	}
	case 3:
	{
		printf("An error occurred: Date format incorrect. Nothing was modified.\n");
		break;
	}
	case 4:
	{
		printf("An error occured: Material does not exist. Nothing was modified.\n");
		break;
	}
	}
}

void list_material_ui(Console *console)
{
	int len = console->bakery_controller->material_repository->length;
	
	if (len == 0) {
		char *str = "There are no materials in the deposit.";
		printf("%s \n", str);
	}
	else {
		printf("The deposit has the following materials:\n");
		for (int i = 0; i < console->bakery_controller->material_repository->length; i++) {
			char str[200];
			material_to_string(console->bakery_controller->material_repository->materials[i], str);
			printf("%s\n", str);
		}
	}
}

void run_app(Console * console)
{
	printf("Bread'n Bagel - v1.2\n");
	//print_menu();
	init_data(console);
	while (1) {
		print_menu();
		int command = read_integer_number();
		if (valid_command(command)) {
			if (command == 0)
				break;
			switch (command)
			{
			case 1:
			{
				add_material_ui(console);
				break;
			}
			case 2:
			{
				delete_material_ui(console);
				break;
			}
			case 3:
			{
				update_material_ui(console);
				break;
			}
			case 4:
			{
				list_material_ui(console);
				break;
			}
			}
		}
		else printf("Invalid command.\n");
	}
}
