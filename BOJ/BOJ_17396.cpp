#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>


using namespace std;

/*
BOJ 17396 백도어
풀이 방법 : 
*/

bool IsVisible[100001] = {};
long long MinTime[100001] = {};

struct Info
{
	int Dest;
	long long Time;
};

struct MoveInfo
{
	long long CurPos;
	long long CurTime;
};

struct cmp
{
	bool operator() (const MoveInfo& Src, const MoveInfo& Dest)
	{
		return Src.CurTime > Dest.CurTime;
	}
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> IsVisible[i];
		MinTime[i] = LLONG_MAX;
	}
	
	vector<vector<Info>> vecGraph(N);
	for (int i = 0; i < M; ++i)
	{
		long long Src, Dest, Time;
		cin >> Src >> Dest >> Time;

		Info S;
		S.Dest = Dest;
		S.Time = Time;
		vecGraph[Src].push_back(S);

		S.Dest = Src;
		vecGraph[Dest].push_back(S);
	}

	MinTime[0] = 0;

	priority_queue<MoveInfo, vector<MoveInfo>, cmp> pqMove;
	MoveInfo Start;
	Start.CurPos = 0;
	Start.CurTime = 0;
	pqMove.push(Start);

	while (!pqMove.empty())
	{
		MoveInfo Cur = pqMove.top();
		pqMove.pop();

		if (MinTime[Cur.CurPos] < Cur.CurTime)
			continue;

		int Size = vecGraph[Cur.CurPos].size();
		for (int i = 0; i < Size; ++i)
		{
			int Dest = vecGraph[Cur.CurPos][i].Dest;
			long long Time = vecGraph[Cur.CurPos][i].Time;

			if (IsVisible[Dest] && Dest != N - 1)
				continue;

			if (MinTime[Dest] <= Cur.CurTime + Time)
				continue;

			MinTime[Dest] = Cur.CurTime + Time;

			if (Dest == N - 1)
				continue;

			MoveInfo Next;
			Next.CurPos = Dest;
			Next.CurTime = Cur.CurTime + Time;
			pqMove.push(Next);
		}
	}

	if (MinTime[N - 1] == LLONG_MAX)
		cout << -1;

	else
		cout << MinTime[N - 1];

}

