#include "Line.h"
#include "Stop.h"

#include <iostream>

std::string Line::getName()
{
	return line_name_;
}

void Line::add_stop(const Stop& stop)
{
	line_stops_.push_back(&stop);
}

void Line::print_stops()
{
	for (const auto& it : line_stops_)
		std::cout << *it << std::endl;
}
