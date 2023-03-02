#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Board.h"
#include"User.h"
#include"Viewer.h"
using namespace std;

class BoardManager
{
public:
    vector<User> users;
    vector<Board> boards;
    int current_user;

    BoardState state;
    Viewer viewer;

};


