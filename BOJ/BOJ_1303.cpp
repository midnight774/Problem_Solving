#include <iostream>
#include <vector>
#include <algorithm>

/*
BOJ 1303 전쟁 - 전투 
풀이 방법 : DFS
*/

using namespace std;

int M, N;
int Power[2] = {};
int DirY[4] = { 0,0,1,-1 };
int DirX[4] = { 1,-1,0,0 };
char Field[101][101] = {};
bool Check[101][101] = {};

void DFS(int CurY, int CurX, int& outCnt, const char CurColor)
{
	for (int i = 0; i < 4; ++i)
	{
		int NextY = CurY + DirY[i];
		int NextX = CurX + DirX[i];

		bool IsOut = NextY >= M || NextY < 0 || NextX >= N || NextX < 0;

		if (IsOut)
			continue;

		if (Check[NextY][NextX])
			continue;

		if (Field[NextY][NextX] != CurColor)
			continue;

		Check[NextY][NextX] = true;
		++outCnt;
		DFS(NextY, NextX, outCnt, CurColor);
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Field[i][j];
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Check[i][j])
				continue;

			int Cnt = 1;
		
			Check[i][j] = true;
			DFS(i, j, Cnt, Field[i][j]);

			if (Field[i][j] == 'W')
				Power[0] += Cnt * Cnt;

			else
				Power[1] += Cnt * Cnt;
		}
	}

	cout << Power[0] << ' ' << Power[1];
}
