#ifndef  STOP_H
#define STOP_H

#include <string>

class Stop
{
public:

	Stop(const int& stop_id, const std::string& stop_name, bool important=false) : stop_id_(stop_id), stop_name_(stop_name), important_(important) {};

	int getId();
	std::string getName();
	bool getImportance();

	friend std::ostream& operator<<(std::ostream& os, const Stop& stop);

private:

	const int stop_id_;
	const std::string stop_name_;
	bool important_;
};

#endif