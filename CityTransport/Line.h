#ifndef  LINE_H
#define LINE_H

#include <string>

class Line
{
public:
	Line(const std::string& line_name) : line_name_(line_name) {};

	std::string getName();

protected:

private:
	std::string line_name_;
};


#endif LINE_H