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
			title = "此文章已被原作者刪除";
			errtype = "此文章已被原作者刪除";
		}
		else if (user.type == "Adiministrator")
		{
			del = true;
			title = "此文章已被管理員刪除";
			std::cout << "輸入刪除原因訊息(因為違反...而被刪除)" << endl;
			std::cin >> errtype;
		}
		else
		{
			std::cout << "權限不足，無法執行這動作" << endl;
		}
	}
	void printpost()
	{
		if (del == false)
		{
			like.printlike();
			cout << "留言:" << endl;
			for (int i = 0; i < comment.size(); i++)
			{
				cout << i << '\t';
				comment[i].printcomment();
			}
		}
		else
		{
			std::cout << "你要找的文章已被刪除" << endl;
			std::cout << errtype << endl;
		}
	}
	void delcommented(int i)
	{
		comment[i].user = "管理員";
		comment[i].content = "此留言因不符合板規已被刪除";
		cout << "輸入刪除原因訊息(因為違反...而被刪除)" << endl;
		cin >> errtype;
	}
	void delcomment(int i)
	{
		comment[i].user = "留言者";
		comment[i].content = "留言已被留言者刪除";
	}
};

