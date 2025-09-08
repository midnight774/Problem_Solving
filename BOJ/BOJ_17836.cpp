#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 17836 공주님을 구해라!
풀이 방법 : BFS

BFS 진행 도중 검을 얻었다면 바로 맨해튼 거리로 최종 시간 구해줄 수 있음
*/

int N, M, T;
int Castle[101][101] = {};
bool Check[101][101] = {};
int DirY[4] = { 1,-1,0,0 };
int DirX[4] = { 0,0,1,-1 };
int MinTime = 20001;

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

	cin >> N >> M >> T;
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> Castle[i][j];

	queue<Info> qInfo;
	Info Start;
	Start.Y = 0;
	Start.X = 0;
	Start.Time = 0;

	qInfo.push(Start);
	while (!qInfo.empty())
	{
		Info Cur = qInfo.front();
		qInfo.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextY = Cur.Y + DirY[i];
			int NextX = Cur.X + DirX[i];

			bool IsOut = NextY >= N || NextY < 0 || NextX >= M || NextX < 0;
			if (IsOut)
				continue;

			if (NextY == N - 1 && NextX == M - 1)
			{
				MinTime = min(MinTime, Cur.Time + 1);
				continue;
			}

			if (Check[NextY][NextX])
				continue;

			Check[NextY][NextX] = true;

			if (Castle[NextY][NextX] == 1)
				continue;

			else if (Castle[NextY][NextX] == 2)
			{
				MinTime = min(MinTime, Cur.Time + 1 + (N - 1) - NextY + (M - 1) - NextX);
				continue;
			}

			Info Next;
			Next.Y = NextY;
			Next.X = NextX;
			Next.Time = Cur.Time + 1;

			qInfo.push(Next);
		}
	}

	if (MinTime <= T)
		cout << MinTime;

	else
		cout << "Fail";

}

