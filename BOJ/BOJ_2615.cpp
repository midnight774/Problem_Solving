#include <iostream>

/*
BOJ 2615번 오목
풀이 방법 : 브루트포스
*/

using namespace std;

int DirY[4] = { 0,1,1,1 };
int DirX[4] = { 1,0,1, -1 };

int Board[19][19] = {};
bool Check[19][19][4] = {};

bool Enable = false;

int DFS(int CurY, int CurX, int Dir, int Color, int Cnt)
{
	int NextY = CurY + DirY[Dir];
	int NextX = CurX + DirX[Dir];

	bool Enable = NextY >= 19 || NextX >= 19 || NextX < 0;

	if (Enable)
		return Cnt;

	if (Board[NextY][NextX] == Color && !Check[NextY][NextX][Dir])
	{
		Check[NextY][NextX][Dir] = true;
		return DFS(NextY, NextX, Dir, Color, Cnt + 1);
	}

	return Cnt;
}

bool DFS(int CurY, int CurX, int Color)
{
	for (int i = 0; i < 4; ++i)
	{
		if (Check[CurY][CurX][i])
			continue;

		Check[CurY][CurX][i] = true;

		int Num = DFS(CurY, CurX, i, Color, 1);

		if (Num == 5)
		{
			cout << Color<<'\n';

			if (i == 3)
			{
				CurY += 4;
				CurX -= 4;
			}
			cout << CurY + 1 << ' ' << CurX + 1;
			return true;
		}
	}

	return false;
}


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);


	for (int i = 0; i < 19; ++i)
		for (int j = 0; j < 19; ++j)
			cin >> Board[i][j];


	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (Board[i][j] == 0)
				continue;

			if (DFS(i, j, Board[i][j]))
				return 0;
			
		}
	}

	cout << 0;

}

