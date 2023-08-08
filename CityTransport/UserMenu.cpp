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


const string UserMenu::working_menu_ = R"(Molimo Vas, odaberite opciju:
1. Prikaz informacija o stajalistu
2. Prikaz informacija o liniji gradskog prevoza
3. Pronalazak putanje između dva stajalista
0. Kraj rada
)";

const string UserMenu::stop_file_prompt_ = R"(Molimo Vas, unesite putanju do fajla sa stajalistima ili kliknite ENTER za učitavanje
podrazumevanog fajla (stajalista.txt):
)";

const string UserMenu::line_file_prompt_ = R"(Molimo Vas, unesite putanju do fajla sa stajalistima ili kliknite ENTER za učitavanje
podrazumevanog fajla (linije.txt):
)";

const string UserMenu::save_stop_prompt_ = R"(Molimo Vas, unesite oznaku stajalista cije informacije želite da prikazete.
)";

const string UserMenu::save_line_prompt_ = R"(Molimo Vas, unesite oznaku linije cije informacije želite da prikazete.
)";

const string UserMenu::path_options_ = R"(Molimo Vas, unesite prioritet za nalazenje putanje:
1. Nema prioriteta (bilo koja putanja)
2. Obilazak svih vaznih stajalista pocev od Vase lokacije
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
        std::cout << stop_file_prompt_;
        std::getline(std::cin, stop_path);
        if (stop_path.empty()) stop_path = "stajalista.txt";
        std::cout << line_file_prompt_;
        std::getline(std::cin, line_path);
        if (line_path.empty()) line_path = "linije.txt";
        loader_ = new Loader(line_path, stop_path);
        std::cout << "Ucitani su fajlovi sa podacima o prevozu";
        app();
    }
    else {
        std::cout << "Hvala Vam na koriscenju aplikacije.";
        return;
    }
}

void UserMenu::app()
{
    int choice;
    std::cout << working_menu_;
    std::cin >> choice;
    int stop_name, path_type, start, stop;
    string line_name;
    while (choice != APP_EXIT) {
        switch (choice) {
            case STOP_INFO:
                std::cout << save_stop_prompt_;
                std::cin >> stop_name;
                loader_->save_stop(stop_name);
                break;
            case LINE_INFO:
                std::cout << save_line_prompt_;
                std::cin >> line_name;
                loader_->save_line(line_name);
                break;
            case FIND_PATH:
                std::cout << path_options_;
                std::cin >> path_type;
                if (path_type == 1) {
                    std::cout << "Unesite pocetno i krajnje stajaliste: ";
                    std::cin >> start >> stop;
                }
                else if (path_type == 2) {
                    std::cout << "Unesite pocetno stajaliste: ";
                    std::cin >> start;
                    stop = -1;
                }
                loader_->searchPath(path_type, start, stop);
                break;
        }
        std::cout << working_menu_;
        std::cin >> choice;
    }
}