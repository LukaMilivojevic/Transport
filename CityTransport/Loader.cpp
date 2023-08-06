#include "Graph.h"
#include "Loader.h"
#include "Line.h"
#include "Stop.h"
#include "Strategy.h"

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <set>

using std::set;

void Loader::load_lines()
{
	std::ifstream input;
	input.open(line_filepath_);
	if (input.is_open()) {
		std::string line_stop, line_name, name;
		while (getline(input, line_stop)) {
			std::list<Stop*> stops;
			std::stringstream ss(line_stop);
			ss >> line_name;
			Line* line = new Line(line_name);
			lines.push_back(line);
			while (ss >> name) {
				line->add_stop(*stop_map[stoi(name)]);
			}
		}
	}
	else {
		std::cout << "File not found." << std::endl;
	}
	input.close();
	graph_ = new Graph(lines);
}

void Loader::load_stops()
{
	std::ifstream input;
	input.open(stop_filepath_);
	if (input.is_open()) {
		std::string stop_text, stop_info, stop_name;
		int stop_id;
		bool important;
		while (getline(input, stop_text)) {
			stop_name = "";
			important = false;
			std::stringstream ss(stop_text);

			ss >> stop_info;
			stop_id = stoi(stop_info);
			while (ss >> stop_info) {
				if (stop_info != "[!]")
					stop_name += stop_info + " ";
				else if (stop_info == "[!]") //za slucaj da uleti random karakter
					important = true;
			}
			if (!important) {
				stop_name.pop_back();
			}
			stops_.push_back(new Stop(stop_id, stop_name, important));
			stop_map[stop_id] = stops_.back();
		}
	}
	else {
		std::cout << "File not found." << std::endl;
	}
	input.close();

	
}

void Loader::save_line(const std::string& line_id)
{
	for (const auto& it : lines)
		if (line_id == it->getName()) {
			
			std::string filepath = "linija_"+it->getName()+".txt";
			std::ofstream save_file;
			save_file.open(filepath);
			save_file <<  *it;
			save_file.close();
			break;
		} 
}

void Loader::save_stop(int id)
{
	set<const Stop*> adj_stops = graph_->find_adj_stops(id);
	set<Line*> lines_in_stop = graph_->find_lines_in_stop(id);
	std::string filepath = "stajaliste_" + std::to_string(id) + ".txt";
	std::ofstream save_file;
	save_file.open(filepath);
	save_file << *stop_map[id] << " [";
	for (const auto& it : lines_in_stop)
		if (it != *lines_in_stop.rbegin())
			save_file << it->getName() << " ";
		else
			save_file << it->getName() << "] {! ";

	for (const auto& it : adj_stops) {
		if (it->getImportance())
			save_file << it->getId() << " ";
	}
	save_file << "!}";
}

void Loader::searchPath()
{
	strategy_ = new AnyPath;
	strategy_->search(*graph_, 1212, 154);
}


