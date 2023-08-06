#ifndef GRAPH_H
#define GRAPH_H

/**
* 	Klasa Graph se koristi za ucitavanje linija i stajalista
*	u graf koji je realizovan koriscenjem mapa i skupova.
* 
*/

#include "Line.h"
#include "Stop.h"

#include <list>
#include <set>
#include <unordered_map>
using std::list;
using std::unordered_map;
using std::set;

class Graph
{
public:
	Graph(const list<Line*>&);
	set<const Stop*>& find_adj_stops(int) ;
	set<Line*>& find_lines_in_stop(int) ;

protected:


private:
	/*
	* Mapa gde je kljuc id stajalista a value je
	* lista susednih stajalista
	*/
	unordered_map<int, set<const Stop*>> adj_;
	
	/*
	* Mapa gde je kljuc id stajalista a value je
	* lista linija koje kroz njega prolaze
	*/
	unordered_map<int, set<Line*>> stop_lines_;
};

#endif