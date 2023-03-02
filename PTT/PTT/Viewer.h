#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Board.h"
#include"User.h"
using namespace std;
enum BoardState
{
	MENU,
	SELECT_BOARD,
	BOARD,
	POST,
	BOARDMAIL,
	MAILPOST
};
class Viewer {
public:
	/* Constructor */
	Viewer()
	{

	};
	void print(BoardState& state,const vector<User>& users, vector<Board> post, int currentPost, int currentuser)
	{
		system("CLS");
		if (state == MENU)
		{
			cout << "          �w��Ө��~�{ �ثe��[" << users.size() << "] ��ϥΪ�" << endl;
			cout << "�п�J�b���W��,�ο�J guess �������[��,�Y�n���U�b���п�J new : ";
		}
		if (state == SELECT_BOARD)
		{
			cout << "��������������������������������������������������������������������������������������������������" << endl;
			cout << "��                                                                                              ��" << endl;
			cout << "��           ��������  ��������       ��        ����        ������                              ��" << endl;
			cout << "��           ��    ��  ��    ��      ����       ��  ��      ��    ��                            ��" << endl;
			cout << "��           ��������  ��    ��     ������      ����        ��     ��                           ��" << endl;
			cout << "��           ��    ��  ��    ��   ��      ��    �� ��       ��    ��                            ��" << endl;
			cout << "��           ��������  ��������  ������������   ��  ��      ������                              ��" << endl;
			cout << "��������������������������������������������������������������������������������������������������" << endl;
			cout << endl;
			cout << "A : ���~��Ͱ�" << endl;
			cout << "B : �����W�b" << endl;
			cout << "C : �����C��" << endl;
			cout << "D : �ʺ��e" << endl;
			cout << "E : �l��A��" << endl;
		}
		if(state == BOARD)
		{
			for (int i = 0; i < post.size(); i++)
			{
				char index = i + 'A';
				cout << index << "    " << "���D:" << post[i].title << '\t' << "�@��:" << post[i].author  << "   �H��:" << post[currentPost].like.likesum << endl;
			}
		}
		if (state == POST)
		{
			cout << "���D:"<< post[currentPost].title << '\t' <<"�@��:" << post[currentPost].author <<  endl;
			cout << "���e:" << post[currentPost].content << endl;
			post[currentPost].printpost();
		}
		if (state == BOARDMAIL)
		{
			for (int i = 0; i < users[currentuser].mail.size(); i++)
			{
				char index = i + 'A';
				cout << index << '\t' << users[currentuser].mail[i].title << '\t' << users[currentuser].mail[i].author << endl;
			}
		}
		if (state == MAILPOST)
		{
			cout << users[currentuser].mail[currentPost].title << '\t' << users[currentuser].mail[currentPost].author << endl;
			cout << users[currentuser].mail[currentPost].content << endl;
		}
	}
};
