#include <iostream>
#include <queue>

using namespace std;

/*
BOJ 3187 양치기 꿍
풀이 방법 : BFS

*/

int R, C;
char Board[251][251] = {};
bool Check[251][251] = {};
int SheepLifeCnt = 0;
int WolfLifeCnt = 0;
int DirY[4] = { 0,0,-1,1 };
int DirX[4] = { -1,1,0,0 };

void BFS(int Y, int X)
{
	queue<pair<int, int>> qPos;
	int WolfCnt = 0;
	int SheepCnt = 0;

	if (Board[Y][X] == 'v')
		++WolfCnt;

	else if (Board[Y][X] == 'k')
		++SheepCnt;

	qPos.push({ Y, X });
	while (!qPos.empty())
	{
		pair<int, int> Cur = qPos.front();
		qPos.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextY = Cur.first + DirY[i];
			int NextX = Cur.second + DirX[i];

			bool IsOut = NextY >= R || NextY < 0 || NextX >= C || NextX < 0;
			if (IsOut)
				continue;

			if (Check[NextY][NextX])
				continue;

			Check[NextY][NextX] = true;

			if (Board[NextY][NextX] == 'v')
				++WolfCnt;

			else if (Board[NextY][NextX] == 'k')
				++SheepCnt;

			else if (Board[NextY][NextX] == '#')
				continue;

			qPos.push({ NextY, NextX });
		}
	}

	if (WolfCnt >= SheepCnt)
		WolfLifeCnt += WolfCnt;

	else
		SheepLifeCnt += SheepCnt;
}


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		cin >> Board[i];
	}

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (Check[i][j])
				continue;

			if (Board[i][j] == '#')
				continue;

			Check[i][j] = true;
			BFS(i, j);
		}
	}

	cout << SheepLifeCnt << ' ' << WolfLifeCnt;

}



