#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 22352번 항체인식
풀이 방법 : DFS
*/

int N, M;
int Before[31][31] = {};
int After[31][31] = {};
bool Check[31][31] = {};

int DirY[4] = { 1,-1,0,0 };
int DirX[4] = { 0,0,1,-1 };

void Update(int CurY, int CurX, const int PrevNum, const int UpdateNum)
{
	for (int i = 0; i < 4; ++i)
	{
		int NextY = CurY + DirY[i];
		int NextX = CurX + DirX[i];

		bool IsOut = NextY <0 || NextY >= N || NextX < 0 || NextX >= M;

		if (IsOut)
			continue;

		if (Check[NextY][NextX])
			continue;

		Check[NextY][NextX] = true;

		if (Before[NextY][NextX] != PrevNum)
			continue;

		Before[NextY][NextX] = UpdateNum;
		Update(NextY, NextX,PrevNum, UpdateNum);
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
			cin >> Before[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> After[i][j];
		}
	}
	
	bool IsUpdated = false;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Before[i][j] != After[i][j])
			{
				Check[i][j] = true;
				int PrevNum = Before[i][j];
				Before[i][j] = After[i][j];
				Update(i, j, PrevNum, After[i][j]);
				IsUpdated = true;
				break;
			}
		}

		if (IsUpdated)
			break;
	}


	if (!IsUpdated)
	{
		cout << "YES";
	}

	else
	{
		bool IsEnable = true;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (Before[i][j] != After[i][j])
				{
					IsEnable = false;
					cout << "NO";
					break;
				}
			}

			if (!IsEnable)
				break;
		}

		if (IsEnable)
			cout << "YES";
	}
}


