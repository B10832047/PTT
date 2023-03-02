#pragma once
#include <iostream>
#include <string>
using namespace std;
class comment
{
public:
	std::string user;
	std::string content;
	void printcomment()
	{
		cout << user << ": " << content << endl;
	}
};
