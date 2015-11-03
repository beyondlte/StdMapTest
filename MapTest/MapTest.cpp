// MapTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// declare a map
	std::map<char, int> firstMap;
	// initialize the map
	firstMap['a'] = 10;
	firstMap['b'] = 30;
	firstMap['c'] = 50;
	firstMap['d'] = 70;

	std::map<char, int> secondMap (firstMap.begin(), firstMap.end());
	// loop through the map
	std::map<char, int>::iterator it;
	for (it = secondMap.begin(); it != secondMap.end(); it++)
	{
		std::cout << it->first << ": " << it->second << "\n";
	}

	return 0;
}

