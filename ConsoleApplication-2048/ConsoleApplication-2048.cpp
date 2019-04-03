// ConsoleApplication-2048.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

#include<stdlib.h>
#include<vector>
#include<string>
#include<time.h>
using namespace std;
void printArray(vector<vector<int>>,int);
void rand2in0(vector<vector<int>>&);///在0的位子随机生成一个2
void movingRule(vector<vector<int>>&, int, int &);
int main()
{
	int ch;
	int score=0;
	vector<int> sub(4, 0);
	vector<vector<int>> res(4, sub);
	rand2in0(res);
	rand2in0(res);
	printArray(res, score);
	while (true)
	{
		if ((ch =_getch()) == 0x1B) break;
		if (ch == 119 || ch == 115 || ch == 97 || ch == 100)
		{
			system("cls");
			movingRule(res, ch,score);
			rand2in0(res);
			printArray(res,score);
			
		}
		
	}
    return 0;
}
void movingRule(vector<vector<int>> &array44, int flag,int &score)
{

	if (flag == 119 || flag == 115)
	{
		for (int i = 0; i < 4; i++)
		{
			vector<int> temp;
			for (int j = 0; j < 4; j++)
			{
				if (array44[j][i] != 0)
				{
					if (temp.empty()) temp.push_back(array44[j][i]);
					else if(temp[temp.size() - 1]== array44[j][i])
					{
						score = score + 2 * temp[temp.size() - 1];
						temp[temp.size() - 1] = -2 * temp[temp.size() - 1];
						
					}
					else
					{
						temp.push_back(array44[j][i]);
					}
				}
			}
			if (temp.size() == 0) continue;
			if (flag == 119)
			{
				for (int k = 0; k < 4; k++)
				{
					if (k < temp.size())
					{
						array44[k][i] = (temp[k]<0 ? -temp[k] : temp[k]);
					}
					else
					{
						array44[k][i] = 0;
					}
				}
			}
			else
			{
				for (int k = 0; k < 4; k++)
				{
					int delta = 4 - temp.size();
					if (k-delta >= 0)
					{
						array44[k][i] = (temp[k-delta]<0 ? -temp[k - delta] : temp[k - delta]);
					}
					else
					{
						array44[k][i] = 0;
					}
				}

			}
			

		}

	}
	else if (flag == 97 || flag == 100)
	{
		for (int i = 0; i < 4; i++)
		{
			vector<int> temp;
			for (int j = 0; j < 4; j++)
			{
				if (array44[i][j] != 0)
				{
					if (temp.empty()) temp.push_back(array44[i][j]);
					else if (temp[temp.size() - 1] == array44[i][j])
					{
						score = score + 2 * temp[temp.size() - 1];
						temp[temp.size() - 1] = -2 * temp[temp.size() - 1];
						
					}
					else
					{
						temp.push_back(array44[i][j]);
					}
				}
			}
			if (temp.size() == 0) continue;
			if (flag == 97)
			{
				for (int k = 0; k < 4; k++)
				{
					if (k < temp.size())
					{
						array44[i][k] = (temp[k]<0 ? -temp[k] : temp[k]);
					}
					else
					{
						array44[i][k] = 0;
					}
				}
			}
			else
			{
				for (int k = 0; k < 4; k++)
				{
					int delta = 4 - temp.size();
					if (k - delta >= 0)
					{
						array44[i][k] = (temp[k - delta]<0 ? -temp[k - delta] : temp[k - delta]);
					}
					else
					{
						array44[i][k] = 0;
					}
				}
			}


		}

	}
	else return;


}
void rand2in0(vector<vector<int>> &array44)
{
	srand((unsigned)time(NULL));
	vector<pair<int,int> > res;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			if (array44[i][j] == 0)
			{
				pair<int, int> temp(i, j);
				res.push_back(temp);
			}
		}

	}
	if (res.size() != 0)
	{
		int index = rand() % res.size();
		array44[res[index].first][res[index].second] = 2;
	}
}
void printArray(vector<vector<int>> array44,int score)
{
	string res;
	for (int i = 0; i < 4; i++)
	{
		string temp;
		for (int j = 0; j < 4; j++)
		{
			if (array44[i][j]==0)
			{
			temp = temp + "    " + " \t| ";
            }
			else
			{
				temp = temp + to_string(array44[i][j]) + " \t| ";
			}
			
		}
		res = res +temp+"\n";
	}
	res = res + "Score: " + to_string(score);
	cout << res <<endl;
}

