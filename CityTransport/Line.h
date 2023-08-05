#ifndef  LINE_H
#define LINE_H

#include "Stop.h"

#include <list>
#include <string>

using std::list;

class Line
{
public:
	Line(const std::string& line_name) : line_name_(line_name) {};

	std::string getName();

	void add_stop(const Stop&);

	void print_stops();

protected:

private:
	std::string line_name_;
	list <const Stop*> line_stops_;
};


#endif LINE_H