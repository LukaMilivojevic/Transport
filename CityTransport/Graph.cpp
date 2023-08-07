#include "Graph.h"
#include "Line.h"
#include "Stop.h"

#include <list>
#include <iostream>
using std::list;

Graph::Graph(const list<Line*>& lines)
{
	list<int> ids;
	bool flag = false;
	int curr_id;
	const Stop* last_stop = nullptr;
	for (const auto& line : lines) {
		flag = false;
		for (const auto& stop : line->get_stops()) {
			curr_id = stop->getId();
			if (!stop_lines_.count(curr_id)) {
				set<Line*> temp;
				stop_lines_[curr_id] = temp;
			}
			stop_lines_[curr_id].insert(line);
			//stop_lines_[curr_id] = line;
			if (!adj_.count(curr_id)) {
				set<const Stop*> temp;
				ids.push_back(curr_id);
				adj_[curr_id] = temp;
			}
			if (flag) {
				adj_[curr_id].insert(last_stop);
				adj_[last_stop->getId()].insert(stop);
			}
			flag = true;
			last_stop = stop;
		}
	}
}

Graph::~Graph()
{
}

set<const Stop*>& Graph::find_adj_stops(int id)
{
	return adj_[id];
}

set<Line*>& Graph::find_lines_in_stop(int id)
{
	return stop_lines_[id];
}
