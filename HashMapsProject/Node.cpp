#include "Node.h"

Node::Node()
{
	this->next = NULL;
}

Node::Node(std::string key, int value)
{
	this->Key = key;
	this->Value = value;
	this->next = NULL;
}

Node::~Node()
{
	delete this->next;
}
