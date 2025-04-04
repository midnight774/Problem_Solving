#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 17090 미로 탈출하기
풀이 방법 : DP, DFS
*/

int N, M;
bool IsVisited[501][501] = {};
int Check[501][501] = {};
char Map[501][501] = {};
int Answer = 0;

int DFS(int Y, int X)
{
	int NextY = Y;
	int NextX = X;

	if (Map[Y][X] == 'D')
		++NextY;

	else if (Map[Y][X] == 'U')
		--NextY;

	else if (Map[Y][X] == 'R')
		++NextX;

	else if (Map[Y][X] == 'L')
		--NextX;

	bool IsOut = NextY >= N || NextY < 0 || NextX >= M || NextX < 0;

	if (IsOut)
	{
		++Answer;
		Check[Y][X] = 1;
		IsVisited[Y][X] = true;
		return Check[Y][X];
	}

	if (!IsVisited[NextY][NextX])
	{
		IsVisited[NextY][NextX] = true;
		Check[Y][X] = DFS(NextY, NextX);
	}

	else
	{
		Check[Y][X] = Check[NextY][NextX];
	}

	Answer += Check[Y][X];

	return Check[Y][X];
	
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> Map[i];
	}


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (IsVisited[i][j])
				continue;

			IsVisited[i][j] = true;
			DFS(i, j);
		}
	}

	cout << Answer;
}

