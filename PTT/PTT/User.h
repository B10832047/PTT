#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"MailBoard.h"
using namespace std;
class User
{
public:
	string name;
	string password;
	string type;
	vector<MailBoard> mail;
};
