#include "UserMenu.h";
#include "Loader.h"

int main() {
	Loader* ld = new Loader("linije.txt", "stajalista.txt");
	ld->load_stops();
	return 0;
}