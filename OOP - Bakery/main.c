#include "UI.h"


int main() {
	MaterialRepository material_repository = create_repository();
	BakeryController bakery_controller = create_controller(&material_repository);
	Console console = create_console(&bakery_controller);

	run_app(&console);
	
	return 0;
}