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
			cout << "          Åwªï¨Ó¨ì¹ê·~§{ ¥Ø«e¦³[" << users.size() << "] ¦ì¨Ï¥ÎªÌ" << endl;
			cout << "½Ð¿é¤J±b¸¹¦WºÙ,©Î¿é¤J guess ¦¨¬°°ÑÆ[ªÌ,­Y­nµù¥U±b¸¹½Ð¿é¤J new : ";
		}
		if (state == SELECT_BOARD)
		{
			cout << "ùÝùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùß" << endl;
			cout << "ùø                                                                                              ùø" << endl;
			cout << "ùø           ¡½¡½¡½¡½  ¡½¡½¡½¡½       ¡½        ¡½¡½        ¡½¡½¡½                              ùø" << endl;
			cout << "ùø           ¡½    ¡½  ¡½    ¡½      ¡½¡½       ¡½  ¡½      ¡½    ¡½                            ùø" << endl;
			cout << "ùø           ¡½¡½¡½¡½  ¡½    ¡½     ¡½¡½¡½      ¡½¡½        ¡½     ¡½                           ùø" << endl;
			cout << "ùø           ¡½    ¡½  ¡½    ¡½   ¡½      ¡½    ¡½ ¡½       ¡½    ¡½                            ùø" << endl;
			cout << "ùø           ¡½¡½¡½¡½  ¡½¡½¡½¡½  ¡½¡½¡½¡½¡½¡½   ¡½  ¡½      ¡½¡½¡½                              ùø" << endl;
			cout << "ùãùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùå" << endl;
			cout << endl;
			cout << "A : ³õ¥~¥ð¾Í°Ï" << endl;
			cout << "B : ­µ¼ÖÅW®b" << endl;
			cout << "C : ¼öªù¹CÀ¸" << endl;
			cout << "D : °Êº©µe" << endl;
			cout << "E : ¶l¥óªA°È" << endl;
		}
		if(state == BOARD)
		{
			for (int i = 0; i < post.size(); i++)
			{
				char index = i + 'A';
				cout << index << "    " << "¼ÐÃD:" << post[i].title << '\t' << "§@ªÌ:" << post[i].author  << "   ¤H®ð:" << post[currentPost].like.likesum << endl;
			}
		}
		if (state == POST)
		{
			cout << "¼ÐÃD:"<< post[currentPost].title << '\t' <<"§@ªÌ:" << post[currentPost].author <<  endl;
			cout << "¤º®e:" << post[currentPost].content << endl;
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
