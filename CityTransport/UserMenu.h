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

	static UserMenu* GetInstance();

	void start();

	void app();

	~UserMenu() {
		delete loader_;
	}
	
protected:
	UserMenu() : loader_(nullptr) {};

	static UserMenu* user_menu_;

	static const string start_user_message_, working_menu_, stop_file_prompt_, line_file_prompt_, save_stop_prompt_, save_line_prompt_, path_options_;

private:
	Loader* loader_;
};


#endif;