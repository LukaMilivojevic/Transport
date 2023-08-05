#ifndef PARSER_H
#define PARSER_H

class Parser
{
protected:
	Parser() = default;

public:
	virtual void parse_into_object() = 0;
};


#endif // !PARSER_H