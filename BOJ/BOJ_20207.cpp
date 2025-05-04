#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 20207번 달력
풀이 방법 : 정렬 + DFS
*/

int N;
bool Check[1001][366] = {};
bool IsVisited[1001][366] = {};

int DirY[5] = { 0,-1,1,1,-1 };
int DirX[5] = { 1,1,1, 0,0 };

void DFS(int CurY, int CurX, int& MaxY, int& MaxX)
{
	for (int i = 0; i < 5; ++i)
	{
		int NextY = CurY + DirY[i];
		int NextX = CurX + DirX[i];

		if (NextY < 1 || NextY > N || NextX < 1 || NextX > 365)
			continue;

		if (IsVisited[NextY][NextX] || !Check[NextY][NextX])
			continue;

		IsVisited[NextY][NextX] = true;

		MaxY = max(MaxY, NextY);
		MaxX = max(MaxX, NextX);

		DFS(NextY, NextX, MaxY, MaxX);
	}

	if (CurX + 1 <= 365)
	{
		if (Check[1][CurX + 1])
		{
			if (!IsVisited[1][CurX + 1])
			{
				IsVisited[1][CurX + 1] = true;
				MaxX = max(MaxX, CurX + 1);

				DFS(1, CurX + 1, MaxY, MaxX);
			}
		}
	}
}

bool Cmp(pair<int, int> Src, pair<int, int> Dest)
{
	if (Src.first == Dest.first)
		return Src.second - Src.first > Dest.second - Dest.first;

	return Src.first < Dest.first;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	vector<pair<int, int>> vecPair(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecPair[i].first >> vecPair[i].second;
	}

	sort(vecPair.begin(), vecPair.end(), Cmp);

	for (int i = 0; i < N; ++i)
	{
		pair<int, int> Cur = vecPair[i];

		int Max = 0;

		for (int j = 1; j <= N; ++j)
		{
			if (!Check[j][Cur.first])
			{
				for (int k = Cur.first; k <= Cur.second; ++k)
				{
					Check[j][k] = true;
				}

				break;
			}
		}
	}

	int Answer = 0;

	for (int i = 1; i <= 365; ++i)
	{
		int MaxY = 1, MaxX = i;

		if (!Check[1][i] || IsVisited[1][i])
			continue;

		IsVisited[1][i] = true;
		DFS(1, i, MaxY, MaxX);

		Answer += (MaxY * (MaxX - i + 1));
	}

	cout << Answer;
}


