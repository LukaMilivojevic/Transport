#ifndef  LOADER_H
#define LOADER_H

#include "Line.h"
#include "Stop.h"

#include <list>
#include <string>
#include <unordered_map>

class Loader
{
public:
	Loader(std::string line_filepath, std::string stop_filepath): line_filepath_(line_filepath), stop_filepath_(stop_filepath) {};

	void load_lines();
	void load_stops();

private:
	std::string line_filepath_;
	std::string stop_filepath_;
	//std::unordered_map<Line*, std::list<Stop*>> map;
	std::unordered_map<int, Stop*> stop_map;
	std::unordered_map<int, const Stop*> line_stop_map;
	std::list<Stop*> stops_;
	std::list<Line*> lines;
};


#endif LOADER_H