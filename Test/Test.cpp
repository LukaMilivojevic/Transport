#include "UserMenu.h";
#include "Loader.h"
#include "Info.h";

#include <crtdbg.h>

int main() {
	Loader* ld = new Loader("linije.txt", "stajalista.txt");
	ld->save_line("MINI");
	ld->save_stop(1221);
	ld->searchPath();
	delete ld;
	_CrtDumpMemoryLeaks();
	return 0;
}