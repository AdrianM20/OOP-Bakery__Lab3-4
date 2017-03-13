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
	printf("|| 2 - List materials                        ||\n");
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
	if (command >= 0 && command <= 2)
		return 1;
	return 0;
}

void read_string(char *input, int length)
/* Wannabe read string with whitespaces */
{
	fgets(input, sizeof(char) * length, stdin);
	sscanf(input, "%[^\n]", input);
}

void add_material_ui(Console* console)
{
	char name[30], supplier[50];
	int quantity, day, month, year, res;

	printf("Insert name of material: ");
	//TODO read strings with whitespaces
	scanf("%29s", name);
	printf("Insert supplier for material: ");
	scanf("%49s", supplier);
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
		printf("Material added succesfully.");
		break;
	}
	case 1:
	{
		printf("An error occurred: Name or supplier length must be at least 3. Material not added.");
		break;
	}
	case 2:
	{
		printf("An error occurred: Quantity should be at least 1. Material not added,");
		break;
	}
	case 3:
	{
		printf("An error occurred: Date format incorrect. Material not added.");
		break;
	}
	}
}

void run_app(Console * console)
{
	printf("Bread'n Bagel - v1.0\n");
	//print_menu();
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
				break;
			}
		}
		else printf("Invalid command.\n");
	}
}
