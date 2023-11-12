#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
	std::unordered_map<std::string, int> MyMap;
	
	std::pair<std::string, int> p("ABC", 1);

	MyMap.insert(p);

	MyMap["DEF"] = 2;

	//Find or access elements in the Map 

	std::cout << MyMap["ABC"] << "\n";
	std::cout << MyMap.at("ABC") << "\n";

	//std::cout << MyMap["GHI"] << "\n";

	//Check presence of a key within a MyMap cause cannot use .at() or []

	if (MyMap.count("GHI") > 0)
	{
		std::cout << "GHI is present\n";
	}
	else
	{
		std::cout << "GHI is NOT present\n";
	}

	std::cout << "Size of our Map is: " << MyMap.size() << "\n";

	MyMap["GHI"] = 5;

	//Update Keys []

	MyMap["ABC"] = 20;

	//Find size of map 

	std::cout << "Size of our Map is: " << MyMap.size() << "\n";

	//Erasing Map Elements 

	MyMap.erase("GHI");


	return 0;
}