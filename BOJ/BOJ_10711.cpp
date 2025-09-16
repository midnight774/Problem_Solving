#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 10711 모래성
풀이 방법 : BFS
*/

int N, M;
int DirY[8] = { 1,1,1,0,0,-1,-1,-1 };
int DirX[8] = { -1,0,1,-1,1,-1,0,1 };
string Board[1001] = {};
int Cnt[1001][1001] = {};

struct Info
{
	int Y;
	int X;
	int Time;
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		cin >> Board[i];


	queue<Info> qInfo;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Board[i][j] == '.')
			{
				qInfo.push({ i,j,0 });
			}
		}
	}

	int MaxTime = 0;
	while (!qInfo.empty())
	{
		Info CurInfo = qInfo.front();
		qInfo.pop();

		MaxTime = max(MaxTime, CurInfo.Time);

		for (int i = 0; i < 8; ++i)
		{
			int Y = CurInfo.Y + DirY[i];
			int X = CurInfo.X + DirX[i];

			if (Y < 0 || Y >= N || X < 0 || X >= M)
				continue;

			if (Board[Y][X] == '.')
				continue;

			++Cnt[Y][X];

			int Intensity = (int)(Board[Y][X] - '0');
			if (Cnt[Y][X] >= Intensity)
			{
				Board[Y][X] = '.';
				Info NextInfo;
				NextInfo.Y = Y;
				NextInfo.X = X;
				NextInfo.Time = CurInfo.Time + 1;
				qInfo.push(NextInfo);
			}
		}
	}

	cout << MaxTime;
	
}

