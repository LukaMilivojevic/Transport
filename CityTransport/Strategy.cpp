#include "Line.h"
#include "Graph.h"
#include "Stop.h"
#include "Strategy.h"


#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using std::queue;
using std::unordered_map;
using std::string;


void AnyPath::search(Graph& graph, int start, int stop)
{
	queue<int> qu;
	unordered_map<int, int> visited;
	unordered_map<int, string> stop_line;
	qu.push(start);
	visited[start] = start;
	Line* line = *graph.find_lines_in_stop(start).begin();
	stop_line[start] = line->getName();
	int curr, curr_explored;
	bool flag = true;
	while (!qu.empty() && flag) {
		curr = qu.front();
		qu.pop();

		for (const auto& it : graph.find_adj_stops(curr)) {
			curr_explored = it->getId();
			if (curr_explored == stop) {
				visited[curr_explored] = curr;
				stop_line[curr_explored] = line->getName();
				flag = false;
				break;
			}
			if (!visited.count(curr_explored)) {
				if (graph.find_lines_in_stop(curr_explored).find(line) == graph.find_lines_in_stop(curr_explored).end()) {
					line = *graph.find_lines_in_stop(curr_explored).begin();
				}
				stop_line[curr_explored] = line->getName();
				qu.push(curr_explored);
				visited[curr_explored] = curr;

			};
		}
	}
	if (!flag) {
		list<int> out;
		while (curr_explored != start) {
			out.push_back(curr_explored);
			curr_explored = visited[curr_explored];
		}
		out.push_back(start);
		out.reverse();
		int last = out.back();
		out.pop_back();
		string stop_name = "";
		bool first_flag = true;
		int prev;
		std::string filepath = "stajaliste_" + std::to_string(start) + "_" + std::to_string(stop) + ".txt";
		std::ofstream save_file;
		save_file.open(filepath);
		for (const auto& it : out) { 
			if (stop_name != stop_line[it] && first_flag) {
				stop_name = stop_line[it];
				save_file << "->" << stop_line[it] << std::endl;
				first_flag = false;
			}
			else if (stop_name != stop_line[it]) {
				save_file << std::endl << "->" << stop_line[it] << std::endl;
				stop_name = stop_line[it];
				save_file << prev << " ";
			}
			save_file << it << " ";
			prev = it;
		}
		save_file << last;
		
		std::cout << "Putanja je sacuvana na lokaciji: " << filepath << std::endl;
	}
	else {
		std::cout << "Ne postoji put do trazene stanice";
	}
}




void LeastChanges::search(Graph& graph, int start, int stop)
{
}

void AllImportant::search(Graph& graph, int start, int stop)
{
	queue<int> qu;
	unordered_map<int, int> visited;
	unordered_map<int, string> stop_line;
	qu.push(start);
	visited[start] = start;
	Line* line = *graph.find_lines_in_stop(start).begin();
	stop_line[start] = line->getName();
	int curr, curr_explored;
	while (!qu.empty()) {
		curr = qu.front();
		qu.pop();
		for (const auto& it : graph.find_adj_stops(curr)) {
			curr_explored = it->getId();
			if (!visited.count(curr_explored)) {
				if (graph.find_lines_in_stop(curr_explored).find(line) == graph.find_lines_in_stop(curr_explored).end()) {
					line = *graph.find_lines_in_stop(curr_explored).begin();
				}
				for (auto const& imp : graph.find_adj_stops(curr_explored)) {
					if (imp->getImportance())
						important_.insert(imp->getId());
				}
				stop_line[curr_explored] = line->getName();
				qu.push(curr_explored);
				visited[curr_explored] = curr;

			};
		}
	}
	std::string filepath = "bitnaStajalista_" + std::to_string(start) + ".txt";
	std::ofstream save_file;
	save_file.open(filepath);
	for (const auto& it : important_) {
			search_output(graph, start, it, save_file);
			start = it;
	}
	std::cout << "Putanja je sacuvana na lokaciji: " << filepath << std::endl;
}

void AllImportant::search_output(Graph& graph, int start, int stop, std::ofstream& save_file)
{
	queue<int> qu;
	unordered_map<int, int> visited;
	unordered_map<int, string> stop_line;
	qu.push(start);
	visited[start] = start;
	Line* line = *graph.find_lines_in_stop(start).begin();
	stop_line[start] = line->getName();
	int curr, curr_explored;
	bool flag = true;
	while (!qu.empty() && flag) {
		curr = qu.front();
		qu.pop();

		for (const auto& it : graph.find_adj_stops(curr)) {
			curr_explored = it->getId();
			if (curr_explored == stop) {
				visited[curr_explored] = curr;
				stop_line[curr_explored] = line->getName();
				flag = false;
				break;
			}
			if (!visited.count(curr_explored)) {
				if (graph.find_lines_in_stop(curr_explored).find(line) == graph.find_lines_in_stop(curr_explored).end()) {
					line = *graph.find_lines_in_stop(curr_explored).begin();
				}
				stop_line[curr_explored] = line->getName();
				qu.push(curr_explored);
				visited[curr_explored] = curr;

			};
		}
	}
	if (!flag) {
		list<int> out;
		while (curr_explored != start) {
			out.push_back(curr_explored);
			curr_explored = visited[curr_explored];
		}
		out.push_back(start);
		out.reverse();
		int last = out.back();
		out.pop_back();
		string stop_name = "";
		bool first_flag = true;
		int prev;

		for (const auto& it : out) {
			if (important_.find(it) != important_.end())
				important_.erase(it);
			if (stop_name != stop_line[it] && first_flag) {
				stop_name = stop_line[it];
				save_file << "->" << stop_line[it] << std::endl;
				first_flag = false;
			}
			else if (stop_name != stop_line[it]) {
				save_file << std::endl << "->" << stop_line[it] << std::endl;
				stop_name = stop_line[it];
				save_file << prev << " ";
			}
			save_file << it << " ";
			prev = it;
		}
		save_file << last << std::endl;
	}
	else {
		std::cout << "Ne postoji put do trazene stanice";
	}
}
