#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 18223 민준이와 마산 그리고 건우
풀이 방법 : 다익스트라

1에서 시작하는 다익스트라 한 번 해서 V까지의 최단 거리 구한다.
P에서 시작하는 다익스트라 한 번 더 해서 (P->1) + (P->V) 최단 거리 구함
둘이 비교해서 같으면 SAVE HIM 출력 뒤에꺼가 더 크면 GOOD BYE 출력
*/

int V, E, P;
vector<vector<pair<int,int>>> vecGraph;

struct Info
{
	int Pos;
	int Dist;
};

struct cmp
{
	bool operator() (const Info& Src, const Info& Dest) const
	{
		return Src.Dist > Dest.Dist;
	}
};

int MinDist[5001] = {};

void Dijkstra(int StartPos)
{
	for (int i = 1; i <= V; ++i)
	{
		MinDist[i] = 987654321;
	}

	MinDist[StartPos] = 0;

	Info Start;
	Start.Pos = StartPos;
	Start.Dist = 0;

	priority_queue<Info, vector<Info>, cmp> pqInfo;
	pqInfo.push(Start);

	while (!pqInfo.empty())
	{
		Info Cur = pqInfo.top();
		pqInfo.pop();

		int Size = vecGraph[Cur.Pos].size();

		for (int i = 0; i < Size; ++i)
		{
			int NextPos = vecGraph[Cur.Pos][i].first;
			int Dist = vecGraph[Cur.Pos][i].second;

			if (MinDist[NextPos] <= Cur.Dist + Dist)
				continue;

			MinDist[NextPos] = Cur.Dist + Dist;

			Info NextInfo;
			NextInfo.Pos = NextPos;
			NextInfo.Dist = Cur.Dist + Dist;
			pqInfo.push(NextInfo);
		}
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> V >> E >> P;

	MinDist[1] = 0;
	vecGraph.resize(V + 1);

	for (int i = 0; i < E; ++i)
	{
		int Src, Dest, Time;
		cin >> Src >> Dest >> Time;
		vecGraph[Src].push_back({ Dest, Time });
		vecGraph[Dest].push_back({ Src, Time });
	}

	Dijkstra(1);
	int Min = MinDist[V];
	Dijkstra(P);
	
	if (Min == MinDist[1] + MinDist[V])
		cout << "SAVE HIM";

	else
		cout << "GOOD BYE";
	
}

