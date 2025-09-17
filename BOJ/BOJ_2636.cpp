#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

/*
BOJ 2636 치즈
풀이 방법 : BFS
*/

int N, M;
int Cnt = 0;
int DirY[4] = { 0,0,1,-1 };
int DirX[4] = { 1,-1,0,0 };
int Board[101][101] = {};
bool Check[101][101] = {};
bool Melted[101][101] = {};

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
			cin >> Board[i][j];
			if (Board[i][j] == 1)
				++Cnt;
		}
	}

	int StartY = 0;
	int StartX = 0;
	int Time = 0;
	int LastMelt = 0;

	while (Cnt > 0)
	{
		int MeltCnt = 0;

		queue<pair<int, int>> qPos;
		qPos.push({ StartY, StartX });
		Check[StartY][StartX] = true;

		while (!qPos.empty())
		{
			pair<int, int> CurPos = qPos.front();
			qPos.pop();

			for (int i = 0; i < 4; ++i)
			{
				pair<int, int> Next = CurPos;
				Next.first += DirY[i];
				Next.second += DirX[i];

				if (Next.first < 0 || Next.first >= N
					|| Next.second < 0 || Next.second >= M)
					continue;

				if (Check[Next.first][Next.second])
					continue;

				Check[Next.first][Next.second] = true;
				
				if (Board[Next.first][Next.second] == 1
					&& !Melted[Next.first][Next.second])
				{
					Melted[Next.first][Next.second] = true;
					++MeltCnt;
				}

				else
					qPos.push(Next);
			}
		}

		++Time;

		if (MeltCnt == Cnt)
		{
			LastMelt = MeltCnt;
		}

		else
		{
			memset(Check, 0, 101 * 101);
		}
		Cnt -= MeltCnt;
	}

	cout << Time << '\n' << LastMelt;

}

