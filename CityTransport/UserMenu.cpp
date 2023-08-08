#include "UserMenu.h"

#include <iostream>
#include <string>


UserMenu* UserMenu::user_menu_ = nullptr;;

using std::string;

const string UserMenu::user_message_ = R"(Dobrodošli u simulator mreže gradskog prevoza. Molimo Vas, odaberite opciju:
										1. Učitavanje podataka o mreži gradskog prevoza 
										0. Kraj rada)";

UserMenu* UserMenu::GetInstance()
{
    if (user_menu_ == nullptr) {
        user_menu_ = new UserMenu;//(value);
    }
    return user_menu_;
}

void UserMenu::ispis()
{
    std::cout << "radi";
}
