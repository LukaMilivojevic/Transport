#include "UserMenu.h";
#include "Loader.h"
#include "Info.h"

int main() {
	Loader* ld = new Loader("linije.txt", "stajalista.txt");
	ld->save_line("MINI");
	ld->save_stop(1221);
	ld->searchPath();
	return 0;
}