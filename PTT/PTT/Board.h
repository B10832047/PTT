#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Comment.h"
#include"User.h"
#include"Like.h"
using namespace std;
class Board
{
public:
	bool del = false;
	string title;
	string author;
	string content;
	vector <comment> comment;
	string errtype;
	Like like ;
	void deletepost(User user)
	{
		if (user.name == author)
		{
			del = true;
			title = "���峹�w�Q��@�̧R��";
			errtype = "���峹�w�Q��@�̧R��";
		}
		else if (user.type == "Adiministrator")
		{
			del = true;
			title = "���峹�w�Q�޲z���R��";
			std::cout << "��J�R����]�T��(�]���H��...�ӳQ�R��)" << endl;
			std::cin >> errtype;
		}
		else
		{
			std::cout << "�v�������A�L�k����o�ʧ@" << endl;
		}
	}
	void printpost()
	{
		if (del == false)
		{
			like.printlike();
			cout << "�d��:" << endl;
			for (int i = 0; i < comment.size(); i++)
			{
				cout << i << '\t';
				comment[i].printcomment();
			}
		}
		else
		{
			std::cout << "�A�n�䪺�峹�w�Q�R��" << endl;
			std::cout << errtype << endl;
		}
	}
	void delcommented(int i)
	{
		comment[i].user = "�޲z��";
		comment[i].content = "���d���]���ŦX�O�W�w�Q�R��";
		cout << "��J�R����]�T��(�]���H��...�ӳQ�R��)" << endl;
		cin >> errtype;
	}
	void delcomment(int i)
	{
		comment[i].user = "�d����";
		comment[i].content = "�d���w�Q�d���̧R��";
	}
};

