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
	printf("\n------------Choose an option---------------\n");
	printf("1 - Add material\n");
	printf("2 - List materials\n");
	printf("\-------------Choose an option---------------\n");
}

void run_app(Console * console)
{
	printf("Bread'n Bagel - v1.0\n");
	print_menu();
	system("pause");
}
