#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "Node.h"
#include "MyMap.h"

std::vector<int> RemoveDuplicates(int* arr, int n)
{
	std::vector<int> output;
	std::unordered_map<int, bool> RemoveDupesMap;

	for (size_t i = 0; i < n; i++)
	{
		if (RemoveDupesMap.count(arr[i]) == 0)
		{
			output.push_back(arr[i]);
			RemoveDupesMap[arr[i]] = true;
		}
		else
		{
			//Not necessary, but nice to have
			std::cout << "Duplicate Found!\n";
		}
	}

	return output;
}


int main()
{
	std::unordered_map<std::string, int> MyMap1;
	
	std::pair<std::string, int> p("ABC", 1);

	MyMap1.insert(p);

	MyMap1["DEF"] = 2;

	//Find or access elements in the Map 

	std::cout << MyMap1["ABC"] << "\n";
	std::cout << MyMap1.at("ABC") << "\n";

	//std::cout << MyMap["GHI"] << "\n";

	//Check presence of a key within a MyMap cause cannot use .at() or []

	if (MyMap1.count("GHI") > 0)
	{
		std::cout << "GHI is present\n";
	}
	else
	{
		std::cout << "GHI is NOT present\n";
	}

	std::cout << "Size of our Map is: " << MyMap1.size() << "\n";

	MyMap1["GHI"] = 5;

	//Update Keys []

	MyMap1["ABC"] = 20;

	//Find size of map 

	std::cout << "Size of our Map is: " << MyMap1.size() << "\n";

	//Erasing Map Elements 

	MyMap1.erase("GHI");

	int DuplicatesArray[] = { 1, 5 ,2 ,4, 4, 3, 3, 6, 7, 1, 1, 2 };
	std::vector<int> OutputVector = RemoveDuplicates(DuplicatesArray, 12);

	for (size_t i = 0; i < OutputVector.size(); i++)
	{
		std::cout << OutputVector.at(i) << "\n";
	}

	std::unordered_map<std::string, int> IteratorMap;

	IteratorMap["ABD"] = 1;
	IteratorMap["DDE"] = 5;
	IteratorMap["MST"] = 6;
	IteratorMap["SEP"] = 9;
	IteratorMap["SAP"] = 14;
	IteratorMap["CRP"] = 42;
	IteratorMap["CDP"] = 26;

	//My raw version to initialize on one line and then iterate via For Loop 
	std::unordered_map<std::string, int>::iterator IT = IteratorMap.begin();

	std::cout << "Using an iterator over the Unordered Map\n";

	for (size_t i = 0; i < IteratorMap.size(); i++)
	{
		std::cout << IT->second << "\n";
		IT++;
	}

	//From the video, can also use auto function for iterators 
	for (auto IT2 = IteratorMap.begin(); IT2 != IteratorMap.end(); IT2++)
	{
		std::cout << IT2->second << "\n";
	}

	if (IteratorMap.find("SAP") == IteratorMap.end())
	{
		std::cout << "Not Present\n";
	}
	else
	{
		std::cout << "The Element is Present\n";
	}

	std::unordered_map<std::string, int>::iterator IT3 = IteratorMap.find("SAP");

	IteratorMap.erase(IT3);

	if (IteratorMap.find("SAP") == IteratorMap.end())
	{
		std::cout << "Not Present\n";
	}
	else
	{
		std::cout << "The Element is Present\n";
	}

	MyMap OurMap;

	for (size_t i = 0; i < 10; i++)
	{
		char c = i;
		std::string Key = "ade";
		//Key = Key + c;
		int Value = i + 1;
		std::cout << Key << " " << OurMap.GetValue(Key);
		std::cout << OurMap.GetLoadFactor();
	}
	std::cout << OurMap.size();

	return 0;
}