#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>


/*

벨만 포드 알고리즘

특정 출발 정점에서 시작하여
모든 정점까지의 최단 거리를
구하는 알고리즘

음수 사이클 감지 가능하므로
음수 간선이 포함되어있어도 가능하다.

작동 방식 : 
특정 정점까지의 최단 거리 이동은
최대 N-1번의 정점 이동을 통해 
이동 가능할 것이라 가정한다.

그러므로 밑 과정을 N-1번 반복한다.

1. 최단 거리 테이블을 초기화 한 뒤 (INF값으로)
2. 시작 정점을 지정한다. (시작 정점 Dist값을 0으로 지정)
3. 도달한 적이 있는 정점에서 출발하는 간선만 고려하며(Dist[i] != INF)
다음 간선으로 이동해나가면서 최단 거리 갱신해나간다.

다 끝나고 만약 N 번째에도 갱신이 된다면 그건 음수 사이클이 있는 것이다.
*/

using namespace std;

int N, M;
long long Dist[501] = {};
long long INF = LLONG_MAX;
bool IsMinusCycle = false;

struct Edge
{
	int Src;
	int Dest;
	long long Cost;
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		Dist[i] = INF;

	vector<Edge> vecEdge(M);

	for (int i = 0; i < M; ++i)
	{
		cin >> vecEdge[i].Src >> vecEdge[i].Dest >> vecEdge[i].Cost;
	}

	Dist[1] = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Dist[vecEdge[j].Src] == INF)
				continue;

			int Src = vecEdge[j].Src;
			int Dest = vecEdge[j].Dest;
			long long Cost = vecEdge[j].Cost;

			if (Dist[Src] + Cost < Dist[Dest])
			{
				if (i == N - 1)
				{
					IsMinusCycle = true;
				}

				Dist[Dest] = Dist[Src] + Cost;
			}
		}
	}

	if (IsMinusCycle)
		cout << -1;

	else
	{
		for (int i = 2; i <= N; ++i)
		{
			if (Dist[i] != INF)
				cout << Dist[i];
			else
				cout << -1;

			cout << '\n';
		}

	}

}
