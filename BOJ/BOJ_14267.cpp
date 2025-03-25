#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 14267 회사 문화 1
풀이 방법 : DP, DFS
*/

vector<vector<int>> vecRoot;
int Score[100001] = {};
bool Check[100001] = {};

void DFS(int CurIdx, int CurScore)
{
	int Size = vecRoot[CurIdx].size();

	for (int i = 0; i < Size; ++i)
	{
		int Next = vecRoot[CurIdx][i];

		if (Check[Next])
			continue;

		Check[Next] = true;
		Score[Next] += CurScore;
		DFS(Next, Score[Next]);
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vecRoot.resize(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		int R;
		cin >> R;

		if (R == -1)
			continue;

		vecRoot[R].push_back(i);
	}

	for (int i = 0; i < M; ++i)
	{
		int Idx, W;
		cin >> Idx >> W;

		Score[Idx] += W;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (Check[i])
			continue;

		Check[i] = true;
		DFS(i, Score[i]);
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << Score[i] << ' ';
	}
}

