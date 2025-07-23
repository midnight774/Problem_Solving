
#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 17616 등수 찾기
풀이 방법 : DFS

순방향 역방향 DFS 한번씩 돌려서 
X보다 성적 좋은 애들 수, 안 좋은 애들 수 각각 카운팅
*/

bool Check[100001] = {};

vector<vector<int>> vecGraph;
vector<vector<int>> vecRevGraph;

void DFS(int CurPos, const vector<vector<int>>& Graph, int& Cnt)
{
	int Size = Graph[CurPos].size();
	for (int i = 0; i < Size; ++i)
	{
		int Next = Graph[CurPos][i];

		if (Check[Next])
			continue;

		Check[Next] = true;
		++Cnt;

		DFS(Next, Graph, Cnt);
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M, X;
	cin >> N >> M >> X;
	vecGraph.resize(N + 1);
	vecRevGraph.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;

		vecGraph[A].push_back(B);
		vecRevGraph[B].push_back(A);
	}

	int U = 0;
	Check[X] = true;
	DFS(X, vecGraph, U);
	U = N - U;

	for (int i = 1; i <= N; ++i)
		Check[i] = false;

	int V = 0;
	Check[X] = true;
	DFS(X, vecRevGraph, V);
	V += 1;
	
	cout << min(U, V) << ' ' << max(U, V);
}

