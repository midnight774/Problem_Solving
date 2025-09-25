#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 2253 점프
풀이 방법 : BFS

*/

bool Small[10001] = {};
bool Check[10001][10001] = {};
int Scale[3] = { -1,0,1 };

struct Info
{
	int Pos;
	int Jump;
	int Cnt;
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int S;
		cin >> S;
		Small[S] = true;
	}

	queue<Info> qInfo;
	Info Start;
	Start.Pos = 1;
	Start.Jump = 0;
	Start.Cnt = 0;

	qInfo.push(Start);
	while (!qInfo.empty())
	{
		Info Cur = qInfo.front();
		qInfo.pop();

		for (int i = 0; i < 3; ++i)
		{
			int JumpPower = Cur.Jump + Scale[i];

			if (JumpPower <= 0)
				continue;

			Info Next;
			Next.Pos = Cur.Pos + JumpPower;
			if (Next.Pos > N || Small[Next.Pos])
				continue;

			Next.Jump = JumpPower;
			if (Check[Next.Pos][JumpPower])
				continue;

			if (Next.Pos == N)
			{
				cout << Cur.Cnt + 1;
				return 0;
			}
			Check[Next.Pos][JumpPower] = true;

			Next.Cnt = Cur.Cnt + 1;
			qInfo.push(Next);
		}
	}
	
	cout << -1;
}

