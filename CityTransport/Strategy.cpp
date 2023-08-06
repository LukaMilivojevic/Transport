#include "Line.h"
#include "Graph.h"
#include "Stop.h"
#include "Strategy.h"


#include <iostream>
#include <queue>
#include <unordered_map>

using std::queue;
using std::unordered_map;


void AnyPath::search(Graph& graph, int start, int stop)
{
	queue<int> qu;
	unordered_map<int, int> visited;
	qu.push(start);
	visited[start] = start;
	int curr, curr_explored;
	bool flag = true;
	while (!qu.empty() && flag) {
		curr = qu.front();
		qu.pop();

		for (const auto& it : graph.find_adj_stops(curr)) {
			curr_explored = it->getId();
			if (curr_explored == stop) {
				visited[curr_explored] = curr;
				flag = false;
				break;
			}
			if (!visited.count(curr_explored)) {
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
		for (const auto& it : out) {
			std::cout << it << " --> ";
		}
		std::cout << last;
	}
	else {
		std::cout << "Ne postoji put do trazene stanice";
	}
}

void LeastChanges::search(Graph& graph, int start, int stop)
{
	std::cout << "LEAST CHANGES";
}
