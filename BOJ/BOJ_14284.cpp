#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

/*
BOJ 14284 간선 이어가기 2
풀이 방법 : 다익스트라
*/

int MinCost[5001] = {};

struct Info
{
	int Pos;
	int	Cost;
};

struct cmp
{
	bool operator() (const Info& Src, const Info& Dest)
	{
		return Src.Cost > Dest.Cost;
	}
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int,int>>> vecGraph(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest, Cost;
		cin >> Src >> Dest >> Cost;
		vecGraph[Src].push_back(pair<int, int>(Dest, Cost));
		vecGraph[Dest].push_back(pair<int, int>(Src, Cost));
	}

	int S, T;
	cin >> S >> T;

	for (int i = 1; i <= N; ++i)
	{
		MinCost[i] = INT_MAX;
	}

	priority_queue<Info, vector<Info>, cmp> pqInfo;
	Info Start;
	Start.Pos = S;
	Start.Cost = 0;
	pqInfo.push(Start);

	while (!pqInfo.empty())
	{
		Info Cur = pqInfo.top();
		pqInfo.pop();

		int Size = vecGraph[Cur.Pos].size();

		bool Enable = false;

		for (int i = 0; i < Size; ++i)
		{
			int Next = vecGraph[Cur.Pos][i].first;
			int Cost = vecGraph[Cur.Pos][i].second;

			if (Cur.Cost + Cost < MinCost[Next])
			{
				Info NextInfo;
				NextInfo.Pos = Next;
				NextInfo.Cost = Cur.Cost + Cost;
				MinCost[Next] = Cur.Cost + Cost;

				pqInfo.push(NextInfo);
			}
		}
	}

	cout << MinCost[T];
	
}

