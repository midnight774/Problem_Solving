#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 14502번 연구소
풀이 방법 : 브루트 포스
*/

int N, M;
int Field[8][8] = {};
int DirY[4] = { 1,-1,0,0 };
int DirX[4] = { 0,0,1,-1 };
int Max = 0;

void DFS(int CurY, int CurX, int WallCnt)
{
	if (WallCnt == 3)
	{
		int CurField[8][8] = {};
		queue<pair<int, int>> qPos;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				CurField[i][j] = Field[i][j];
				if (CurField[i][j] == 2)
				{
					qPos.push({ i,j });
				}
			}
		}

		while (!qPos.empty())
		{
			pair<int, int> Cur = qPos.front();
			qPos.pop();

			for (int i = 0; i < 4; ++i)
			{
				int NextY = Cur.first + DirY[i];
				int NextX = Cur.second + DirX[i];

				bool IsOut = NextY >= N || NextY < 0 || NextX >= M || NextX < 0;

				if (IsOut)
					continue;

				if (CurField[NextY][NextX] != 0)
					continue;

				CurField[NextY][NextX] = 2;
				qPos.push({ NextY, NextX });
			}
		}

		int Cnt = 0;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (CurField[i][j] == 0)
				{
					++Cnt;
				}
			}
		}

		Max = max(Cnt, Max);
		return;
	}

	for (int i = CurY; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Field[i][j] == 0)
			{
				Field[i][j] = 1;
				DFS(i, j, WallCnt + 1);
				Field[i][j] = 0;
			}
		}
	}

}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Field[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Field[i][j] == 0)
			{
				Field[i][j] = 1;
				DFS(i, j, 1);
				Field[i][j] = 0;
			}
		}
	}

	cout << Max;
}


