#pragma once
#include<string>
class Node
{
public:
	std::string Key;

	int Value;

	Node* next;

	Node();

	Node(std::string key, int value);

	~Node();
	
};

