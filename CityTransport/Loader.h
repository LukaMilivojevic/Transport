#ifndef  LOADER_H
#define LOADER_H
/**
* 	Klasa Loader se koristi za ucitavanje linija i stajalista
*	iz ulaznih fajlova, kao i njihovo cuvanje u fajlove.
*	Klasa sadrzi podobjekat klase Graph koja se koristi za 
*	kreiranje grafa iz ucitanih linija i stanica.
*/


#include "Graph.h"
#include "Line.h"
#include "Stop.h"
#include "Strategy.h"

#include <list>
#include <string>
#include <unordered_map>

class Loader
{
public:
	Loader(std::string line_filepath, std::string stop_filepath): line_filepath_(line_filepath), stop_filepath_(stop_filepath), graph_(nullptr), strategy_(nullptr) {
		load_stops();
		load_lines();
	};

	/**
	* Ucitavanje linija iz fajla u listu pokazivaca na objekte klase Line
	*/
	void load_lines();

	/**
	* Ucitavanje stajalista iz fajla u listu pokazivaca na objekte klase Stop
	*/
	void load_stops();

	/**
	* Cuvanje linija u txt fajl oblika linija_nazivLinije.txt
	*/
	void save_line(const std::string&);

	/**
	* Cuvanje stajalista u txt fajl oblika linija_nazivStajalista.txt
	*/
	void save_stop(int);

	void searchPath();

private:
	Strategy* strategy_;
	Graph* graph_;
	std::string line_filepath_;
	std::string stop_filepath_;
	std::unordered_map<int, Stop*> stop_map; // kljuc id stajalista, value pokazivac na objekat tog stajalista
	std::unordered_map<int, const Stop*> line_stop_map; // kljuc id linije, value pokazivac na stajalista kojima vozi ta linija
	std::list<Stop*> stops_; // sva stajalista
	std::list<Line*> lines; // sve linije
};


#endif LOADER_H