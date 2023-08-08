#ifndef USERMENU_H
#define USERMENU_H

#include "Loader.h"

#include <string>
using std::string;

class UserMenu
{
public:

	UserMenu(UserMenu& other) = delete;

	void operator=(const UserMenu&) = delete;

	static UserMenu* GetInstance();//const std::string& value);

	void start();

	void app();

	~UserMenu() {
		if (!loader_)
			delete loader_;
	}
	
protected:
	UserMenu() : loader_(nullptr) {};

	static UserMenu* user_menu_;

	static const string start_user_message_;

	static const string working_menu_;

	static const string stop_prompt_;

	static const string line_prompt_;

private:
	Loader* loader_;
};


#endif;