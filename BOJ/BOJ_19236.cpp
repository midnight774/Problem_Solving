#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

/*
BOJ 19236번 청소년 상어
풀이 방법 : 백트래킹
*/

struct Info
{
	int PosY;
	int PosX;
};

int Max = 0;
int DirY[8] = { -1,-1,0,1,1,1,0,-1 };
int DirX[8] = { 0,-1,-1, -1,0,1,1,1 };

pair<int, int> Board[4][4] = {};
vector<Info> vecInfo(17);
bool Check[17] = {};


void Solve(int Y, int X, int Dir, int CurScore)
{
	Max = max(CurScore, Max);

	pair<int, int> TempBoard[4][4];
	memcpy(TempBoard, Board, sizeof(pair<int, int>) * 16);
	vector<Info> vecTempInfo(17);
	memcpy(&vecTempInfo[0], &vecInfo[0], sizeof(Info) * 17);

	for (int i = 1; i <= 16; ++i)
	{
		if (Check[i])
			continue;

		int CurY = vecInfo[i].PosY;
		int CurX = vecInfo[i].PosX;

		bool Enable = false;
		int Idx = Board[CurY][CurX].second;

		for (int j = 0; j < 8; ++j)
		{
			Idx %= 8;

			int NextY = CurY + DirY[Idx];
			int NextX = CurX + DirX[Idx];

			if (NextY < 0 || NextY >= 4 || NextX < 0 || NextX >= 4)
			{
				++Idx;
				continue;
			}

			if (NextY == Y && NextX == X)
			{
				++Idx;
				continue;
			}

			Enable = true;
			break;
		}

		if (Enable)
		{
			int NextY = CurY + DirY[Idx];
			int NextX = CurX + DirX[Idx];
			
			pair<int,int> Temp = Board[NextY][NextX];
			Board[NextY][NextX] = Board[CurY][CurX];
			Board[CurY][CurX] = Temp;

			Info TempInfo = vecInfo[Board[NextY][NextX].first];
			vecInfo[Board[NextY][NextX].first] = vecInfo[Board[CurY][CurX].first];
			vecInfo[Board[CurY][CurX].first] = TempInfo;

			Board[NextY][NextX].second = Idx;
		}
	}


	for (int i = 1; i <= 3; ++i)
	{
		int NextY = Y + DirY[Dir] * i;
		int NextX = X + DirX[Dir] * i;

		if (NextY < 0 || NextY >= 4 || NextX < 0 || NextX >= 4)
			break;

		int Num = Board[NextY][NextX].first;

		if (Check[Num])
			continue;

		Check[Num] = true;
		Solve(NextY, NextX, Board[NextY][NextX].second, CurScore + Num);
		Check[Num] = false;
	}

	memcpy(Board, TempBoard, sizeof(pair<int, int>) * 16);
	memcpy(&vecInfo[0], &vecTempInfo[0], sizeof(Info) * 17);

}


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> Board[i][j].first >> Board[i][j].second;
			Board[i][j].second -= 1;

			vecInfo[Board[i][j].first].PosY = i;
			vecInfo[Board[i][j].first].PosX = j;
		}
	}

	Check[Board[0][0].first] = true;
	Solve(0, 0, Board[0][0].second, Board[0][0].first);

	cout << Max;
}


