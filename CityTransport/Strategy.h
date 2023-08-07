#ifndef STRATEGY_H
#define STRATEGY_H

#include "Graph.h"

class Strategy
{
public:
	virtual void search(Graph& graph, int start, int stop) = 0;
};

/**/
class AnyPath : public Strategy
{
	virtual void search(Graph& graph, int start, int stop);
};

class LeastChanges : public Strategy
{
	virtual void search(Graph& graph, int start, int stop);
};

class AllImportant : public Strategy
{
	virtual void search(Graph& graph, int start, int stop);
};

#endif