#pragma once
#include <iostream>
#include <string>
#include <vector>

struct thumb
{
	std::string name;
	int like;
	int dislike;
};
class Like
{
public:

	int likesum = 0;
	int dislikesum = 0;
	std::vector <thumb> list;
	void like(std::string name)
	{
		int canfind = -1;
		int check = 0;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].name == name)
			{
				canfind = i;
				check = 1;
				break;
			}
		}
		if (check == 0)
		{
			thumb newt;
			newt.name = name;
			newt.like = 0;
			newt.dislike = 0;
			list.push_back(newt);
			canfind = list.size() - 1;
		}
		if (canfind > -1)
		{
			if (list[canfind].like == 0 && list[canfind].dislike == 0)
			{
				list[canfind].like = 1;
				std::cout << "���g���\" << std::endl;
				likesum++;
			}
			else if (list[canfind].like == 0 && list[canfind].dislike == 1)
			{
				list[canfind].like = 1;
				list[canfind].dislike = 0;
				std::cout << "���g���\" << std::endl;
				likesum++;
				dislikesum--;
			}
			else
			{
				list[canfind].like = 0;
				std::cout << "�A�w�������g" << std::endl;
				likesum--;
			}
		}
	}

	void dislike(std::string name)
	{
		int canfind = -1;
		int check = 0;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].name == name)
			{
				canfind = i;
				check = 1;
				break;
			}
		}
		if (check == 0)
		{
			thumb newt;
			newt.name = name;
			newt.dislike = 0;
			newt.like = 0;
			list.push_back(newt);
			canfind = list.size() - 1;
		}
		if (canfind > -1)
		{
			if (list[canfind].dislike == 0 && list[canfind].like == 0)
			{
				list[canfind].dislike = 1;
				std::cout << "���g���\" << std::endl;
				dislikesum++;
			}
			else if (list[canfind].dislike == 0 && list[canfind].like == 1)
			{
				list[canfind].dislike = 1;
				list[canfind].like = 0;
				std::cout << "���g���\" << std::endl;
				dislikesum++;
				likesum--;
			}
			else
			{
				list[canfind].dislike = 0;
				std::cout << "�A�w�������g" << std::endl;
				dislikesum--;
			}
		}
	}

	void printlike()
	{
		if (likesum >= 2)
		{
			std::cout << "�g: " << likesum << "(���z)" << " �����w: " << dislikesum << std::endl;
		}
		else
		{
			std::cout << "�g: " << likesum << " �����w: " << dislikesum << std::endl;
		}
		
	}

};
