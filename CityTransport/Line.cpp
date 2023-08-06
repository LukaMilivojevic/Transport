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

list <const Stop*>& Line::get_stops()
{
	return line_stops_;
}

std::ostream& operator<<(std::ostream& os, const Line& line)
{
	os << line.line_name_ << " " << line.line_stops_.front()->getName() << "->" << line.line_stops_.back()->getName() << std::endl;
	for (const auto& it : line.line_stops_)
		os << *it << std::endl;
	return os;
}
