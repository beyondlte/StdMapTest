// MapTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;

// define a compare function
bool fncomp(char lhs, char rhs)
{
	return lhs < rhs;
}

// define a compare structure
struct classcomp{
	bool operator() (const char* lhs, const char* rhs) const
	{
		// lhs > rhs: 1
		// lhs < rhs: -1
		// lhs == rhs: 0
		return strcmp(lhs, rhs) > 0;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	// declare a map
	// by default, the map is not sorted
	std::map<const char*, int> firstMap;
	// initialize the map
	firstMap["Z"] = 30;
	firstMap["b"] = 10;
	firstMap["y"] = 50;
	firstMap["d"] = 70;

	std::map<const char*, int> secondMap(firstMap.begin(), firstMap.end());
	// loop through the map
	std::map<const char*, int>::iterator it;
	for (it = secondMap.begin(); it != secondMap.end(); it++)
	{
		std::cout << it->first << ": " << it->second << "\n";
	}

	// define thirdMap with a sorted order using classcomp, here classcomp sorted the value in alphabet order
	std::map<const char*, int, classcomp> thirdMap;
	thirdMap["z"] = 10;
	thirdMap["b"] = 20;
	thirdMap["y"] = 50;
	thirdMap["d"] = 40;

	cout << "thirdMap in sorted:\n";
	std::map<const char*, int, classcomp>::iterator cur;
	for (cur = thirdMap.begin(); cur != thirdMap.end(); cur++)
	{
		std::cout << cur->first << ": " << cur->second << "\n";
	}

	return 0;
}

