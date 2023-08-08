#include "UserMenu.h";
#include "Loader.h"

#include <crtdbg.h>

int main() {
	/*Loader* ld = new Loader("linije.txt", "stajalista.txt");
	ld->save_line("MINI");
	ld->save_stop(1221);
	ld->searchPath();
	delete ld;*/
	UserMenu* menu = UserMenu::GetInstance();
	menu->ispis();
	_CrtDumpMemoryLeaks();
	return 0;
}