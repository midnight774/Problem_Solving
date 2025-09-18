#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 1766 문제집
풀이 방법 : 위상 정렬 + 우선순위 큐
*/

int InCnt[32001] = {};
vector<vector<int>> vecGraph;
vector<int> vecAnswer;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vecGraph.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;

		vecGraph[Src].push_back(Dest);
		++InCnt[Dest];
	}

	priority_queue<int, vector<int>, greater<>> pqNum;

	for (int i = 1; i <= N; ++i)
	{
		if (InCnt[i] == 0)
		{
			pqNum.push(i);
		}
	}

	while (!pqNum.empty())
	{
		int Cur = pqNum.top();
		pqNum.pop();
		vecAnswer.push_back(Cur);

		int Size = vecGraph[Cur].size();
		for (int i = 0; i < Size; ++i)
		{
			int Next = vecGraph[Cur][i];

			--InCnt[Next];
			if (InCnt[Next] == 0)
			{
				pqNum.push(Next);
			}
		}
	}

	for (int i = 0; i < N; ++i)
		cout << vecAnswer[i] << ' ';
}

