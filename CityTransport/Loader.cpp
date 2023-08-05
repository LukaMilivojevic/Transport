#include "Loader.h"
#include "Line.h"
#include "Stop.h"

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <sstream>


void Loader::load_lines()
{
	std::ifstream input;
	input.open(line_filepath_);
	if (input.is_open()) {
		std::string line_stop;
		std::string line_name;
		std::string name;
		bool flag = true;
		while (getline(input, line_stop)) {
			std::list<Stop*> stops;
			flag = true;
			std::stringstream ss(line_stop);
			while (ss >> name) {
				if (flag){
					line_name = name;
					flag = false;
				}
				else {
					//Stop* stop = new Stop(name);
					//stops.push_back(stop);
				}
			}
			//Line* line = new Line(line_name);
			//map.insert({line, stops});
			//map.insert(line, stops);
		}
	}
	else {
		std::cout << "File not found." << std::endl;
	}
	input.close();
}

void Loader::load_stops()
{
	std::ifstream input;
	input.open(stop_filepath_);
	std::string stop_text, stop_info;
	bool flag;
	int stop_id;
	std::string stop_name;
	bool important;
	while (getline(input, stop_text)) {
		stop_name = "";
		flag = true;
		important = false;
		std::stringstream ss(stop_text);
		while (ss >> stop_info) {
			if (flag) {
				stop_id = stoi(stop_info);
				flag = false;
			}
			else if (stop_info != "[!]") {
				stop_name += stop_info+" ";
			}
			else if (stop_info == "[!]")
				important = true;
		}
		if (!important) {
			stop_name.pop_back();
		}
		stops_.push_back(new Stop(stop_id, stop_name, important));
	}
	for (const auto& it : stops_) {
		std::cout << *it << std::endl;
	}
	
}


