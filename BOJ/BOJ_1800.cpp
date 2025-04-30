#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 1800번 인터넷 설치
풀이 방법 : 이분 탐색 + 다익스트라

Mid 값으로 정한 값 이하로 N에 도달할 수 있는지 여부를 통해 매개변수 탐색
다익스트라 탐색 도중 Mid값 초과로 드는 간선 갯수가 K개 이하인지 검사하는
방식으로 검사 가능
*/

int N, P, K;
int Dist[1001] = {};
vector<vector<pair<int, int>>> vecCable;


struct Info
{
	int CurPos;
	int OverCnt;
};

struct cmp
{
	bool operator() (const Info& Src, const Info& Dest)
	{
		return Src.OverCnt > Dest.OverCnt;
	}
};

bool Dijkstra(int Condition)
{
	for (int i = 1; i <= N; ++i)
		Dist[i] = 987654321;

	Dist[1] = 0;

	priority_queue<Info, vector<Info>, cmp> pqInfo;
	Info Start;
	Start.CurPos = 1;
	Start.OverCnt = 0;

	pqInfo.push(Start);

	while (!pqInfo.empty())
	{
		Info Cur = pqInfo.top();
		pqInfo.pop();

		int Size = vecCable[Cur.CurPos].size();

		for (int i = 0; i < Size; ++i)
		{
			Info NextInfo = Cur;

			int NextIdx = vecCable[Cur.CurPos][i].first;
			NextInfo.CurPos = NextIdx;
			
			int Cost = vecCable[Cur.CurPos][i].second;
			NextInfo.OverCnt += (Cost > Condition);

			if (NextInfo.OverCnt < Dist[NextIdx])
			{
				Dist[NextIdx] = NextInfo.OverCnt;
				pqInfo.push(NextInfo);
			}

		}
	}

	return Dist[N] <= K;
	
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> P >> K;

	int Left = 0;
	int Right = 0;

	vecCable.resize(N + 1);
	for (int i = 0; i < P; ++i)
	{
		int Src, Dest, Cost;
		cin >> Src >> Dest >> Cost;
		
		vecCable[Src].push_back({ Dest, Cost });
		vecCable[Dest].push_back({ Src, Cost });
		Right = max(Right, Cost);
	}

	int Answer = 987654321;

	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;

		if (Dijkstra(Mid))
		{
			Answer = min(Answer, Mid);
			Right = Mid - 1;
		}

		else
		{
			Left = Mid + 1;
		}
	}

	if (Answer == 987654321)
		cout << -1;

	else
		cout << Answer;

}


