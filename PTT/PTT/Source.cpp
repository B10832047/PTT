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
	char test = 'A';  //主題版名稱
	int currentuser = 0;
	int currentPost = 0;
	while (true)    //執行PTT
	{
		if (test == 'A')
		{
			PTT.viewer.print(PTT.state, PTT.users, A, currentPost, currentuser);  //列印各state畫面
		}
		else if (test == 'B')
		{
			PTT.viewer.print(PTT.state, PTT.users, B, currentPost, currentuser);  //列印各state畫面
		}
		else if (test == 'C')
		{
			PTT.viewer.print(PTT.state, PTT.users, C, currentPost, currentuser);  //列印各state畫面
		}
		else if (test == 'D')
		{
			PTT.viewer.print(PTT.state, PTT.users, D, currentPost, currentuser);  //列印各state畫面
		}
		else if (test == 'E')
		{
			PTT.viewer.print(PTT.state, PTT.users, E, currentPost, currentuser);  //列印各state畫面
		}
		else if (test == 'O')
		{
			PTT.viewer.print(PTT.state, PTT.users, E, currentPost, currentuser);  //列印各state畫面
		}
		if (PTT.state == MENU)
		{
			int checkBack = 1;
			string currentName;
			cin >> currentName;  //輸入第一階段指令
			while (currentName == "new")  //註冊
			{
				checkBack = 0;
				cout << "輸入註冊名稱 : ";
				string name;
				cin >> name;
				int check = 0;
				if (name == "guess")
				{
					check = 1;
					cout << "不可取訪客名稱，請重新";
				}
				for (int i = 0; i < PTT.users.size(); i++)
				{
					if (PTT.users[i].name == name) //註冊失敗
					{
						check = 1;
						cout << "此名稱已被使用，請重新";
						break;
					}
				}
				if (check == 0)  //註冊成功
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
					cout << "註冊已完成，請重新登入" << endl;
					cout << "loading.....";
					Sleep(2000);
				}
			}
			if (currentName == "guess" && checkBack != 0)  //訪客模式
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
						if (PTT.users[i].name == currentName)  //登入成功
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
					if (check == 0)  //登入失敗
					{
						cout << "查無此人，請重新輸入, 若要返回主畫面並註冊帳號，請輸入 back" << endl << "輸入註冊名稱 : ";
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
			cout << "要去哪個板, 請輸入標頭字母,若要登出，請打O : ";
			cin >> test;
			if (test == 'O')
			{
				PTT.state = MENU;
			}
			else if (test == 'E' && currentUser == "guess")
			{
				cout << "權限不足" << endl;
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
			cout << "請輸入想看之文章,若想發布文章請打n,想返回上一頁,請打b, 想登出,請打o : ";
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
				cout << "權限不足" << endl;
				Sleep(1000);
			}
			else if (postName == 'n')
			{
				Board insert;
				insert.author = currentUser;
				string title;
				cout << "標題 : ";
				cin >> title;
				insert.title = title;
				cout << "文章內容 : ";
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
						cout << "找不到此文章，請再輸入一次 : ";
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
						cout << "找不到此文章，請再輸入一次 : ";
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
						cout << "找不到此文章，請再輸入一次 : ";
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
						cout << "找不到此文章，請再輸入一次 : ";
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
					cout << " 留言按 C / 返回按B / 點讚(或收回)按 L / 倒讚(或收回)按 D / 編輯按E / 刪除按X / 刪除留言按Z : ";
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
						cout << "權限不足" << endl;
						Sleep(1000);
						break;
					}
					comment newcomment;
					string str = "";
					string error;
					switch (move)
					{
					case 'C':case 'c':
						cout << "輸入留言: ";
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
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'E':case 'e':
						if (A[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							cout << "有要更改標題嗎(y or n)? " << endl;
							char change;
							cin >> change;
							if (change == 'y')
							{
								string topic;
								cout << "你要更改標題為:" << endl;
								cin >> topic;
								A[currentPost].title = topic;
							}
							cout << "有要更改內容嗎(y or n)? " << endl;
							cin >> change;
							if (change == 'y')
							{
								cout << "輸入文章內容 : ";
								string temp;
								cin >> temp;
								A[currentPost].content = temp;

							}
						}
						else
						{
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'Z':case 'z':

						cout << "你要刪除哪一則留言(輸入數字)? " << endl;
						int delc;
						cin >> error;
						delc = error[0] - '0';
						if (error.size() != 1 || error[0] < '0' || error[0] > '9')
						{
							cout << "輸入格式錯誤，請重新輸入" << endl;
							Sleep(1000);
						}
						else if (!(delc >= 0 && delc < A[currentPost].comment.size()))
						{
							cout << "查無此訊息" << endl;
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
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'B':
						PTT.state = BOARD;
						break;
					default:
						std::cout << "輸入不符合,請重新輸入" << endl;
						Sleep(1000);
					}
					check = 0;
					PTT.viewer.print(PTT.state, PTT.users, A, currentPost, currentuser);
					if (check == 0)
					{
						cout << " 留言按 C / 返回按 B / 點讚按 L / 倒讚按 D / 編輯按E / 刪除按X / 刪除留言按Z : ";
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
					cout << " 留言按 C / 返回按B / 點讚按 L / 倒讚按 D / 編輯按E / 刪除按X / 刪除留言按Z : ";
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
						cout << "權限不足" << endl;
						Sleep(1000);
						break;
					}
					comment newcomment;
					string str = "";
					switch (move)
					{
					case 'C':case 'c':
						cout << "輸入留言: ";
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
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'E':case 'e':
						if (B[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							cout << "有要更改標題嗎(y or n)? " << endl;
							char change;
							cin >> change;
							if (change == 'y')
							{
								string topic;
								cout << "你要更改標題為:" << endl;
								cin >> topic;
								B[currentPost].title = topic;
							}
							cout << "有要更改內容嗎(y or n)? " << endl;
							cin >> change;
							if (change == 'y')
							{
								cout << "輸入文章內容 : ";
								string temp;
								cin >> temp;
								B[currentPost].content = temp;
							}
						}
						else
						{
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'Z':case 'z':
						cout << "你要刪除哪一則留言(輸入數字)? " << endl;
						int delc;
						cin >> delc;
						if (!(delc >= 0 && delc < B[currentPost].comment.size()))
						{
							cout << "查無此訊息" << endl;
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
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'B':
						PTT.state = BOARD;
						break;
					default:
						std::cout << "輸入不符合,請重新輸入" << endl;
						Sleep(1000);
					}
					check = 0;
					PTT.viewer.print(PTT.state, PTT.users, B, currentPost, currentuser);
					if (check == 0)
					{
						cout << " 留言按 C / 返回按 B / 點讚按 L / 倒讚按 D / 編輯按E / 刪除按X / 刪除留言按Z : ";
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
					cout << " 留言按 C / 返回按B / 點讚按 L / 倒讚按 D / 編輯按E / 刪除按X / 刪除留言按Z : ";
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
						cout << "權限不足" << endl;
						Sleep(1000);
						break;
					}
					comment newcomment;
					string str = "";
					switch (move)
					{
					case 'C':case 'c':
						cout << "輸入留言: ";
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
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'E':case 'e':
						if (C[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							cout << "有要更改標題嗎(y or n)? " << endl;
							char change;
							cin >> change;
							if (change == 'y')
							{
								string topic;
								cout << "你要更改標題為:" << endl;
								cin >> topic;
								C[currentPost].title = topic;
							}
							cout << "有要更改內容嗎(y or n)? " << endl;
							cin >> change;
							if (change == 'y')
							{
								cout << "輸入文章內容 : ";
								string temp;
								cin >> temp;
								C[currentPost].content = temp;
							}
						}
						else
						{
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'Z':case 'z':
						cout << "你要刪除哪一則留言(輸入數字)? " << endl;
						int delc;
						cin >> delc;
						if (!(delc >= 0 && delc < C[currentPost].comment.size()))
						{
							cout << "查無此訊息" << endl;
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
								cout << "查無此訊息" << endl;
								Sleep(1000);
							}
						}
						else
						{
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'B':
						PTT.state = BOARD;
						break;
					default:
						std::cout << "輸入不符合,請重新輸入" << endl;
						Sleep(1000);
					}
					check = 0;
					PTT.viewer.print(PTT.state, PTT.users, C, currentPost, currentuser);
					if (check == 0)
					{
						cout << " 留言按 C / 返回按 B / 點讚按 L / 倒讚按 D / 編輯按E / 刪除按X / 刪除留言按Z : ";
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
					cout << " 留言按 C / 返回按B / 點讚按 L / 倒讚按 D / 編輯按E / 刪除按X / 刪除留言按Z : ";
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
						cout << "權限不足" << endl;
						Sleep(1000);
						break;
					}
					comment newcomment;
					string str = "";
					switch (move)
					{
					case 'C':case 'c':
						cout << "輸入留言: ";
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
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'E':case 'e':
						if (D[currentPost].author == currentUser || PTT.users[currentuser].type == "Adiministrator")
						{
							cout << "有要更改標題嗎(y or n)? " << endl;
							char change;
							cin >> change;
							if (change == 'y')
							{
								string topic;
								cout << "你要更改標題為:" << endl;
								cin >> topic;
								D[currentPost].title = topic;
							}
							cout << "有要更改內容嗎(y or n)? " << endl;
							cin >> change;
							if (change == 'y')
							{
								cout << "輸入文章內容 : ";
								string temp;
								cin >> temp;
								D[currentPost].content = temp;
							}
						}
						else
						{
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'Z':case 'z':
						cout << "你要刪除哪一則留言(輸入數字)? " << endl;
						int delc;
						cin >> delc;
						if (!(delc >= 0 && delc < D[currentPost].comment.size()))
						{
							cout << "查無此訊息" << endl;
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
								cout << "查無此訊息" << endl;
								Sleep(1000);
							}
						}
						else
						{
							cout << "權限不符" << endl;
							Sleep(1000);
						}
						break;
					case 'B':
						PTT.state = BOARD;
						break;
					default:
						std::cout << "輸入不符合,請重新輸入" << endl;
						Sleep(1000);
					}
					check = 0;
					PTT.viewer.print(PTT.state, PTT.users, D, currentPost, currentuser);
					if (check == 0)
					{
						cout << " 留言按 C / 返回按 B / 點讚按 L / 倒讚按 D / 編輯按E / 刪除按X / 刪除留言按Z : ";
					}
					cin >> move;
				}
				PTT.state = BOARD;
			}
		}
		else if (PTT.state == MAILPOST && currentUser == "guess")
		{
			cout << "權限不足" << endl;
		}
		else if (PTT.state == MAILPOST)
		{
			string str;
			cout << "要返回請打goBack,要回信請打reply: ";
			cin >> str;
			while (str != "goBack" && str != "reply")
			{
				cout << "錯誤指令,請重新輸入 : ";
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
			cout << "權限不足" << endl;
		}
		else if (PTT.state == BOARDMAIL)
		{
			char postName;
			cout << "請輸入想看之訊息,若想傳送訊息請打n,想返回上一頁,請打b, 想登出,請打o : ";
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
				cout << "想寄給誰:";
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
						cout << "找不到此用戶,請重新輸入,若想返回請打goBack : ";
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
					cout << "標題 : ";
					cin >> title;
					insert.title = title;
					cout << "訊息內容(請輸入z表示結束) : ";  //怎麼新增文章內容改掉
					char temp = '0';
					string content;
					while (temp != 'z')
					{
						cin >> temp;
						content.push_back(temp);
					}
					insert.content = content;
					PTT.users[check].mail.push_back(insert);
					cout << "訊息已傳送....";
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
					cout << "找不到此訊息，請再輸入一次 : ";
				}
			}
		}
	}
}
