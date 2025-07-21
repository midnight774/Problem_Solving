
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
BOJ 14567 선수과목 (Prerequisite) 
풀이 방법 : 위상 정렬
*/

int InCnt[1001] = {};
int Term[1001] = {};
vector<vector<int>> vecGraph;


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

		++InCnt[Dest];
		vecGraph[Src].push_back(Dest);
	}
	
	queue<int> qSubject;

	for (int i = 1; i <= N; ++i)
	{
		if (InCnt[i] == 0)
		{
			qSubject.push(i);
			Term[i] = 1;
		}
	}

	while (!qSubject.empty())
	{
		int Cur = qSubject.front();
		qSubject.pop();

		int Size = vecGraph[Cur].size();
		for (int i = 0; i < Size; ++i)
		{
			int Next = vecGraph[Cur][i];
			--InCnt[Next];

			if(InCnt[Next] == 0)
			{
				qSubject.push(Next);
				Term[Next] = Term[Cur] + 1;
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << Term[i] << ' ';
	}
}

