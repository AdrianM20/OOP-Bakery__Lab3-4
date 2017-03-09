#include "Controller.h"
#pragma once

typedef struct Console {
	BakeryController *bakery_controller;
} Console;

Console create_console(BakeryController *bakery_controller);

void run_app(Console *console);