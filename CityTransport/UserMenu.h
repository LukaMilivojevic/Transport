#ifndef USERMENU_H
#define USERMENU_H

#include <string>
using std::string;

class UserMenu
{
public:

	UserMenu(UserMenu& other) = delete;

	void operator=(const UserMenu&) = delete;

	static UserMenu* GetInstance();//const std::string& value);

	void ispis();
	
protected:
	UserMenu() = default;

	static UserMenu* user_menu_;

	static const string user_message_;

private:
	
};


#endif;