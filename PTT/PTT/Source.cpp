#include<iostream>
#include<vector>
#include<string>
#include"User.h"
#include"Board.h"
#include"Viewer.h"
#include"BoardManager.h"
#include <windows.h>
using namespace std;
int main()
{
	BoardManager PTT;
	PTT.state = MENU;
	string currentUser;
	vector<Board> A, B, C, D, E;
	char test = 'A';  //�D�D���W��
	int currentuser = 0;
	int currentPost = 0;
	while (true)    //����PTT
	{
		if (test == 'A')
		{
			PTT.viewer.print(PTT.state, PTT.users, A, currentPost, currentuser);  //�C�L�Ustate�e��
		}
		else if (test == 'B')
		{
			PTT.viewer.print(PTT.state, PTT.users, B, currentPost, currentuser);  //�C�L�Ustate�e��
		}
		else if (test == 'C')
		{
			PTT.viewer.print(PTT.state, PTT.users, C, currentPost, currentuser);  //�C�L�Ustate�e��
		}
		else if (test == 'D')
		{
			PTT.viewer.print(PTT.state, PTT.users, D, currentPost, currentuser);  //�C�L�Ustate�e��
		}
		else if (test == 'E')
		{
			PTT.viewer.print(PTT.state, PTT.users, E, currentPost, currentuser);  //�C�L�Ustate�e��
		}
		else if (test == 'O')
		{
			PTT.viewer.print(PTT.state, PTT.users, E, currentPost, currentuser);  //�C�L�Ustate�e��
		}
		if (PTT.state == MENU)
		{
			int checkBack = 1;
			string currentName;
			cin >> currentName;  //��J�Ĥ@���q���O
			while (currentName == "new")  //���U
			{
				checkBack = 0;
				cout << "��J���U�W�� : ";
				string name;
				cin >> name;
				int check = 0;
				if (name == "guess")
				{
					check = 1;
					cout << "���i���X�ȦW�١A�Э��s";
				}
				for (int i = 0; i < PTT.users.size(); i++)
				{
					if (PTT.users[i].name == name) //���U����
					{
						check = 1;
						cout << "���W�٤w�Q�ϥΡA�Э��s";
						break;
					}
				}
				if (check == 0)  //���U���\
				{
					cout << "Set your password: ";
					string pass;
					cin >> pass;
					User user;
					user.name = name;
					user.password = pass;
					cout << "Enter your identity(Member or Adiministrator): ";
					string Identity;
					cin >> Identity;
					while (Identity != "Member" && Identity != "Adiministrator")
					{
						cout << "Wrong identity,please enter again." << endl;
						cout << "Enter your identity(Member or Adiministrator): ";
						cin >> Identity;
					}
					user.type = Identity;
					PTT.users.push_back(user);
					currentName = user.name;
					PTT.state = MENU;
					cout << "���U�w�����A�Э��s�n�J" << endl;
					cout << "loading.....";
					Sleep(2000);
				}
			}
			if (currentName == "guess" && checkBack != 0)  //�X�ȼҦ�
			{
				currentUser = "guess";
				User user;
				user.name = currentName;
				user.type = "guess";
				PTT.state = SELECT_BOARD;
			}
			if (currentName != "guess" && currentName != "new" && checkBack != 0)  //input member name
			{
				int check = 0;
				while (check == 0)
				{
					for (int i = 0; i < PTT.users.size(); i++)
					{
						if (PTT.users[i].name == currentName)  //�n�J���\
						{
							currentuser = i;
							cout << "Please enter your password : ";
							string Password;
							cin >> Password;
							while (Password != PTT.users[i].password)
							{
								cout << "Wrong password,please enter again : ";
								cin >> Password;
							}
							cout << "Log in success, please wait for one second.";
							Sleep(2000);
							currentUser = currentName;
							PTT.state = SELECT_BOARD;
							check = 1;
							break;
						}
					}
					if (check == 0)  //�n�J����
					{
						cout << "�d�L���H�A�Э��s��J, �Y�n��^�D�e���õ��U�b���A�п�J back" << endl << "��J���U�W�� : ";
						cin >> currentName;
						if (currentName == "back")
						{
							currentName = "new";
							PTT.state = MENU;
							break;
						}
					}
				}
			}
		}
		else if (PTT.state == SELECT_BOARD)
		{
			cout << "�n�h���ӪO, �п�J���Y�r��,�Y�n�n�X�A�Х�O : ";
			cin >> test;
			if (test == 'O')
			{
				PTT.state = MENU;
			}
			else if (test == 'E' && currentUser == "guess")
			{
				cout << "�v������" << endl;
				Sleep(1000);
				PTT.state = SELECT_BOARD;
			}
			else if (test == 'E')
			{
				PTT.state = BOARDMAIL;
			}
			else
			{
				while ((test < 'A' || test > 'D') && test != 'O' )
				{
					cout << "Wrong Board name, please enter again : ";
					cin >> test;
				}
				PTT.state = BOARD;
				if (test == 'O')
				{
					PTT.state = MENU;
				}
			}
		}
		else if (PTT.state == BOARD)
		{
			char postName;
			cout << "�п�J�Q�ݤ��峹,�Y�Q�o���峹�Х�n,�Q��^�W�@��,�Х�b, �Q�n�X,�Х�o : ";
			cin >> postName;
			if (postName == 'o')
			{
				PTT.state = MENU;
			}
			else if (postName == 'b')
			{
				PTT.state = SELECT_BOARD;
			}
			else if (currentUser == "guess" && postName == 'n')
			{
				cout << "�v������" << endl;
				Sleep(1000);
			}
			else if (postName == 'n')
			{
				Board insert;
				insert.author = currentUser;
				string title;
				cout << "���D : ";
				cin >> title;
				insert.title = title;
				cout << "�峹���e : ";
				string content;
				cin >> content;
				insert.content = content;
				if (test == 'A')
				{
					A.push_back(insert);
				}
				else if (test == 'B')
				{
					B.push_back(insert);
				}
				else if (test == 'C')
				{
					C.push_back(insert);
				}
				else if (test == 'D')
				{
					D.push_back(insert);
				}
			}
			else
			{
				if (test == 'A')
				{
					if (postName - 'A' < A.size() && postName - 'A' >= 0)
					{
						currentPost = postName - 'A';
						PTT.state = POST;
					}
					else
					{
						cout << "�䤣�즹�峹�A�ЦA��J�@�� : ";
						Sleep(1000);
					}
				}
				else if (test == 'B')
				{
					if (postName - 'A' < B.size() && postName - 'A' >= 0)
					{
						currentPost = postName - 'A';
						PTT.state = POST;
					}
					else
					{
						cout << "�䤣�즹�峹�A�ЦA��J�@�� : ";
						Sleep(1000);
					}
				}
				else if (test == 'C')
				{
					if (postName - 'A' < C.size() && postName - 'A' >= 0)
					{
						currentPost = postName - 'A';
						PTT.state = POST;
					}
					else
					{
						cout << "�䤣�즹�峹�A�ЦA��J�@�� : ";
						Sleep(1000);
					}
				}
				else if (test == 'D')
				{
					if (postName - 'A' < D.size() && postName - 'A' >= 0)
					{
						currentPost = postName - 'A';
						PTT.state = POST;
					}
					else
					{
						cout << "�䤣�즹�峹�A�ЦA��J�@�� : ";
						Sleep(1000);
					}
				}
			}

		}
		else if (PTT.state == POST)
		{
			if (test == 'A')
			{
				char move;
				int check = 0;
				if (check == 0) {
					cout << " �d���� C / ��^��B / �I�g(�Φ��^)�� L / ���g(�Φ��^)�� D / �s���E / �R����X / �R���d����Z : ";
					check = 1;
				}
				cin >> move;
				if (move == 'B')
				{
					PTT.state = BOARD;
				}
				while (move != 'B')
				{
					if (currentUser == "guess")
					{
						cout << "�v������" << endl;
						Sleep(1000);
						break;
					}
					comment newcomment;
					string str = "";
					string error;
					switch (move)
					{
					case 'C':case 'c':
						cout << "��J�d��: ";
						newcomment.user = currentUser;
						cin >> str;
						newcomment.content = str;
						A[currentPost].comment.push_back(newcomment);
						break;
					case 'L':case 'l':
						A[currentPost].like.like(currentUser);
						break;
					case 'D':case 'd':
						A[currentPost].like.dislike(currentUser);
						break;
					case 'x':case 'X':
						if (A[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							A[currentPost].deletepost(PTT.users[currentuser]);
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'E':case 'e':
						if (A[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							cout << "���n�����D��(y or n)? " << endl;
							char change;
							cin >> change;
							if (change == 'y')
							{
								string topic;
								cout << "�A�n�����D��:" << endl;
								cin >> topic;
								A[currentPost].title = topic;
							}
							cout << "���n��鷺�e��(y or n)? " << endl;
							cin >> change;
							if (change == 'y')
							{
								cout << "��J�峹���e : ";
								string temp;
								cin >> temp;
								A[currentPost].content = temp;

							}
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'Z':case 'z':

						cout << "�A�n�R�����@�h�d��(��J�Ʀr)? " << endl;
						int delc;
						cin >> error;
						delc = error[0] - '0';
						if (error.size() != 1 || error[0] < '0' || error[0] > '9')
						{
							cout << "��J�榡���~�A�Э��s��J" << endl;
							Sleep(1000);
						}
						else if (!(delc >= 0 && delc < A[currentPost].comment.size()))
						{
							cout << "�d�L���T��" << endl;
							Sleep(1000);
						}
						else if (PTT.users[currentuser].type == "Adiministrator" || A[currentPost].comment[delc].user == currentUser)
						{
							if (A[currentPost].comment[delc].user == currentUser)
							{
								if (delc >= 0 && delc < A[currentPost].comment.size())
								{
									A[currentPost].delcomment(delc);
								}
							}
							else if (PTT.users[currentuser].type == "Adiministrator")
							{
								if (delc >= 0 && delc < A[currentPost].comment.size())
								{
									A[currentPost].delcommented(delc);
								}
							}
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'B':
						PTT.state = BOARD;
						break;
					default:
						std::cout << "��J���ŦX,�Э��s��J" << endl;
						Sleep(1000);
					}
					check = 0;
					PTT.viewer.print(PTT.state, PTT.users, A, currentPost, currentuser);
					if (check == 0)
					{
						cout << " �d���� C / ��^�� B / �I�g�� L / ���g�� D / �s���E / �R����X / �R���d����Z : ";
					}
					cin >> move;
				}
				PTT.state = BOARD;
			}
			else if (test == 'B')
			{
				char move;
				int check = 0;
				if (check == 0) {
					cout << " �d���� C / ��^��B / �I�g�� L / ���g�� D / �s���E / �R����X / �R���d����Z : ";
					check = 1;
				}
				cin >> move;
				if (move == 'B')
				{
					PTT.state = BOARD;
				}
				while (move != 'B')
				{
					if (currentUser == "guess")
					{
						cout << "�v������" << endl;
						Sleep(1000);
						break;
					}
					comment newcomment;
					string str = "";
					switch (move)
					{
					case 'C':case 'c':
						cout << "��J�d��: ";
						newcomment.user = currentUser;
						cin >> str;
						newcomment.content = str;
						B[currentPost].comment.push_back(newcomment);
						break;
					case 'L':case 'l':
						B[currentPost].like.like(currentUser);
						break;
					case 'D':case 'd':
						B[currentPost].like.dislike(currentUser);
						break;
					case 'x':case 'X':
						if (B[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							B[currentPost].deletepost(PTT.users[currentuser]);
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'E':case 'e':
						if (B[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							cout << "���n�����D��(y or n)? " << endl;
							char change;
							cin >> change;
							if (change == 'y')
							{
								string topic;
								cout << "�A�n�����D��:" << endl;
								cin >> topic;
								B[currentPost].title = topic;
							}
							cout << "���n��鷺�e��(y or n)? " << endl;
							cin >> change;
							if (change == 'y')
							{
								cout << "��J�峹���e : ";
								string temp;
								cin >> temp;
								B[currentPost].content = temp;
							}
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'Z':case 'z':
						cout << "�A�n�R�����@�h�d��(��J�Ʀr)? " << endl;
						int delc;
						cin >> delc;
						if (!(delc >= 0 && delc < B[currentPost].comment.size()))
						{
							cout << "�d�L���T��" << endl;
							Sleep(1000);
						}
						else if (PTT.users[currentuser].type == "Adiministrator" || B[currentPost].comment[delc].user == currentUser)
						{
							if (B[currentPost].comment[delc].user == currentUser)
							{
								if (delc >= 0 && delc < B[currentPost].comment.size())
								{
									B[currentPost].delcomment(delc);
								}
							}
							else if (PTT.users[currentuser].type == "Adiministrator")
							{
								if (delc >= 0 && delc < B[currentPost].comment.size())
								{
									B[currentPost].delcommented(delc);
								}
							}
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'B':
						PTT.state = BOARD;
						break;
					default:
						std::cout << "��J���ŦX,�Э��s��J" << endl;
						Sleep(1000);
					}
					check = 0;
					PTT.viewer.print(PTT.state, PTT.users, B, currentPost, currentuser);
					if (check == 0)
					{
						cout << " �d���� C / ��^�� B / �I�g�� L / ���g�� D / �s���E / �R����X / �R���d����Z : ";
					}
					cin >> move;
				}
				PTT.state = BOARD;
			}
			else if (test == 'C')
			{
				char move;
				int check = 0;
				if (check == 0) {
					cout << " �d���� C / ��^��B / �I�g�� L / ���g�� D / �s���E / �R����X / �R���d����Z : ";
					check = 1;
				}
				cin >> move;
				if (move == 'B')
				{
					PTT.state = BOARD;
				}
				while (move != 'B')
				{
					if (currentUser == "guess")
					{
						cout << "�v������" << endl;
						Sleep(1000);
						break;
					}
					comment newcomment;
					string str = "";
					switch (move)
					{
					case 'C':case 'c':
						cout << "��J�d��: ";
						newcomment.user = currentUser;
						cin >> str;
						newcomment.content = str;
						C[currentPost].comment.push_back(newcomment);
						break;
					case 'L':case 'l':
						C[currentPost].like.like(currentUser);
						break;
					case 'D':case 'd':
						C[currentPost].like.dislike(currentUser);
						break;
					case 'x':case 'X':
						if (C[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							C[currentPost].deletepost(PTT.users[currentuser]);
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'E':case 'e':
						if (C[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							cout << "���n�����D��(y or n)? " << endl;
							char change;
							cin >> change;
							if (change == 'y')
							{
								string topic;
								cout << "�A�n�����D��:" << endl;
								cin >> topic;
								C[currentPost].title = topic;
							}
							cout << "���n��鷺�e��(y or n)? " << endl;
							cin >> change;
							if (change == 'y')
							{
								cout << "��J�峹���e : ";
								string temp;
								cin >> temp;
								C[currentPost].content = temp;
							}
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'Z':case 'z':
						cout << "�A�n�R�����@�h�d��(��J�Ʀr)? " << endl;
						int delc;
						cin >> delc;
						if (!(delc >= 0 && delc < C[currentPost].comment.size()))
						{
							cout << "�d�L���T��" << endl;
							Sleep(1000);
						}
						else if (PTT.users[currentuser].type == "Adiministrator" || C[currentPost].comment[delc].user == currentUser)
						{
							if (C[currentPost].comment[delc].user == currentUser)
							{
								if (delc >= 0 && delc < C[currentPost].comment.size())
								{
									C[currentPost].delcomment(delc);
								}
							}
							else if (PTT.users[currentuser].type == "Adiministrator")
							{
								if (delc >= 0 && delc < C[currentPost].comment.size())
								{
									C[currentPost].delcommented(delc);
								}
							}
							else
							{
								cout << "�d�L���T��" << endl;
								Sleep(1000);
							}
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'B':
						PTT.state = BOARD;
						break;
					default:
						std::cout << "��J���ŦX,�Э��s��J" << endl;
						Sleep(1000);
					}
					check = 0;
					PTT.viewer.print(PTT.state, PTT.users, C, currentPost, currentuser);
					if (check == 0)
					{
						cout << " �d���� C / ��^�� B / �I�g�� L / ���g�� D / �s���E / �R����X / �R���d����Z : ";
					}
					cin >> move;
				}
				PTT.state = BOARD;
			}
			else if (test == 'D')
			{
				char move;
				int check = 0;
				if (check == 0) {
					cout << " �d���� C / ��^��B / �I�g�� L / ���g�� D / �s���E / �R����X / �R���d����Z : ";
					check = 1;
				}
				cin >> move;
				if (move == 'B')
				{
					PTT.state = BOARD;
				}
				while (move != 'B')
				{
					if (currentUser == "guess")
					{
						cout << "�v������" << endl;
						Sleep(1000);
						break;
					}
					comment newcomment;
					string str = "";
					switch (move)
					{
					case 'C':case 'c':
						cout << "��J�d��: ";
						newcomment.user = currentUser;
						cin >> str;
						newcomment.content = str;
						D[currentPost].comment.push_back(newcomment);
						break;
					case 'L':case 'l':
						D[currentPost].like.like(currentUser);
						break;
					case 'D':case 'd':
						D[currentPost].like.dislike(currentUser);
						break;
					case 'x':case 'X':
						if (D[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							D[currentPost].deletepost(PTT.users[currentuser]);
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'E':case 'e':
						if (D[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							cout << "���n�����D��(y or n)? " << endl;
							char change;
							cin >> change;
							if (change == 'y')
							{
								string topic;
								cout << "�A�n�����D��:" << endl;
								cin >> topic;
								D[currentPost].title = topic;
							}
							cout << "���n��鷺�e��(y or n)? " << endl;
							cin >> change;
							if (change == 'y')
							{
								cout << "��J�峹���e : ";
								string temp;
								cin >> temp;
								D[currentPost].content = temp;
							}
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'Z':case 'z':
						cout << "�A�n�R�����@�h�d��(��J�Ʀr)? " << endl;
						int delc;
						cin >> delc;
						if (!(delc >= 0 && delc < D[currentPost].comment.size()))
						{
							cout << "�d�L���T��" << endl;
							Sleep(1000);
						}
						else if (PTT.users[currentuser].type == "Adiministrator" || D[currentPost].comment[delc].user == currentUser)
						{
							if (D[currentPost].comment[delc].user == currentUser)
							{
								if (delc >= 0 && delc < D[currentPost].comment.size())
								{
									D[currentPost].delcomment(delc);
								}
							}
							else if (PTT.users[currentuser].type == "Adiministrator")
							{
								if (delc >= 0 && delc < D[currentPost].comment.size())
								{
									A[currentPost].delcommented(delc);
								}
							}
							else
							{
								cout << "�d�L���T��" << endl;
								Sleep(1000);
							}
						}
						else
						{
							cout << "�v������" << endl;
							Sleep(1000);
						}
						break;
					case 'B':
						PTT.state = BOARD;
						break;
					default:
						std::cout << "��J���ŦX,�Э��s��J" << endl;
						Sleep(1000);
					}
					check = 0;
					PTT.viewer.print(PTT.state, PTT.users, D, currentPost, currentuser);
					if (check == 0)
					{
						cout << " �d���� C / ��^�� B / �I�g�� L / ���g�� D / �s���E / �R����X / �R���d����Z : ";
					}
					cin >> move;
				}
				PTT.state = BOARD;
			}
		}
		else if (PTT.state == MAILPOST && currentUser == "guess")
		{
			cout << "�v������" << endl;
		}
		else if (PTT.state == MAILPOST)
		{
			string str;
			cout << "�n��^�Х�goBack,�n�^�H�Х�reply: ";
			cin >> str;
			while (str != "goBack" && str != "reply")
			{
				cout << "���~���O,�Э��s��J : ";
				cin >> str;
			}
			if (str == "goBack")
			{
				PTT.state = BOARD;
			}
			else if (str == "reply")
			{
				PTT.state = BOARDMAIL;
			}
		}
		else if (PTT.state == BOARDMAIL && currentUser == "guess")
		{
			cout << "�v������" << endl;
		}
		else if (PTT.state == BOARDMAIL)
		{
			char postName;
			cout << "�п�J�Q�ݤ��T��,�Y�Q�ǰe�T���Х�n,�Q��^�W�@��,�Х�b, �Q�n�X,�Х�o : ";
			cin >> postName;
			if (postName == 'o')
			{
				PTT.state = MENU;
			}
			else if (postName == 'b')
			{
				PTT.state = SELECT_BOARD;
			}
			else if (postName == 'n')
			{
				string des;
				cout << "�Q�H����:";
				cin >> des;
				int check = -1;
				while (check == -1)
				{
					for (int i = 0; i < PTT.users.size(); i++)
					{
						if (PTT.users[i].name == des)
						{
							check = i;
							break;
						}
					}
					if (check == -1)
					{
						cout << "�䤣�즹�Τ�,�Э��s��J,�Y�Q��^�Х�goBack : ";
						cin >> des;
						if (des == "goBack")
						{
							PTT.state = BOARD;
							check = -2;
						}
					}
				}
				if (check != -2)
				{
					MailBoard insert;
					insert.author = currentUser;
					string title;
					cout << "���D : ";
					cin >> title;
					insert.title = title;
					cout << "�T�����e(�п�Jz��ܵ���) : ";  //���s�W�峹���e�ﱼ
					char temp = '0';
					string content;
					while (temp != 'z')
					{
						cin >> temp;
						content.push_back(temp);
					}
					insert.content = content;
					PTT.users[check].mail.push_back(insert);
					cout << "�T���w�ǰe....";
					Sleep(2000);
					PTT.state = BOARDMAIL;
				}
			}
			else
			{
				if (postName - 'A' < PTT.users[currentuser].mail.size() && postName - 'A' >= 0)
				{
					currentPost = postName - 'A';
					PTT.state = MAILPOST;
				}
				else
				{
					cout << "�䤣�즹�T���A�ЦA��J�@�� : ";
				}
			}
		}
	}
}
