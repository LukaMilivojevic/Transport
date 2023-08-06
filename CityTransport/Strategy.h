#ifndef STRATEGY_H
#define STRATEGY_H


class Strategy
{
public:
	virtual void search() = 0;
};

class AnyPath : public Strategy
{
	virtual void search();
};

class LeastChanges : public Strategy
{
	virtual void search();
};

#endif