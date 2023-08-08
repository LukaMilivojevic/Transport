#include "UserMenu.h"
#include "Loader.h"

#include <iostream>
#include <string>

using std::string;

enum start_options { EXIT,  LOAD };

enum working_menu_options { APP_EXIT, STOP_INFO , LINE_INFO, FIND_PATH };

UserMenu* UserMenu::user_menu_ = nullptr;;

const string UserMenu::start_user_message_ = R"(Dobrodosli u simulator mreze gradskog prevoza. Molimo Vas, odaberite opciju:
1. Ucitavanje podataka o mreži gradskog prevoza 
0. Kraj rada
)";


const string UserMenu::working_menu_ = R"(Mreza gradskog prevoza je uspešno ucitana. Molimo Vas, odaberite opciju:
1. Prikaz informacija o stajalistu
2. Prikaz informacija o liniji gradskog prevoza
3. Pronalazak putanje između dva stajalista
0. Kraj rada
)";

const string UserMenu::stop_prompt_ = R"(Molimo Vas, unesite putanju do fajla sa stajalistima ili kliknite ENTER za učitavanje
podrazumevanog fajla (stajalista.txt):
)";

const string UserMenu::line_prompt_ = R"(Molimo Vas, unesite putanju do fajla sa stajalistima ili kliknite ENTER za učitavanje
podrazumevanog fajla (linije.txt):
)";

UserMenu* UserMenu::GetInstance()
{
    if (user_menu_ == nullptr) {
        user_menu_ = new UserMenu;//(value);
    }
    return user_menu_;
}

void UserMenu::start()
{
    int choice;
    std::cout << start_user_message_;
    std::cin >> choice;
    string stop_path, line_path;
    if (choice == LOAD) {
        std::cin.ignore(INT_MAX, '\n'); // praznjenje buffera
        std::cout << stop_prompt_;
        std::getline(std::cin, stop_path);
        if (stop_path.empty()) stop_path = "stajalista.txt";
        std::cout << line_prompt_;
        std::getline(std::cin, line_path);
        if (line_path.empty()) line_path = "linije.txt";
        loader_ = new Loader(line_path, stop_path);
        
    }
    else {
        std::cout << "Hvala Vam na koriscenju aplikacije.";
        return;
    }
}

void UserMenu::app()
{
}