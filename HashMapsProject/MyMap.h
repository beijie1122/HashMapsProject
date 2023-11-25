#pragma once
#include "Node.h"
#include <iostream>
class MyMap
{
private:
	Node** buckets;
	int Count;
	int NumBuckets;

	int GetBucketIndex(std::string key);

	void Rehash();

public:

	int size();

	int GetValue(std::string key);

	void Insert(std::string key, int value);

	int Remove(std::string key);

	double GetLoadFactor();

	MyMap();

	~MyMap();

};

