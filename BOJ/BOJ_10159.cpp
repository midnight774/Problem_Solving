#include <iostream>
#include <vector>
#include <memory.h>

/*
BOJ 10159 저울
풀이 방법 : DFS

무거운 방향, 가벼운 방향 DFS 두 번
 */

using namespace std;

bool Check[101] = {};
vector<vector<int>> vecTree;
vector<vector<int>> vecRevTree;

void DFS(int Cur, int& Cnt)
{
	int Size = vecTree[Cur].size();

	for (int i = 0; i < Size; ++i)
	{
		int Next = vecTree[Cur][i];

		if (Check[Next])
			continue;

		Check[Next] = true;
		++Cnt;
		DFS(Next, Cnt);
	}
}

void DFSRev(int Cur, int& Cnt)
{
	int Size = vecRevTree[Cur].size();

	for (int i = 0; i < Size; ++i)
	{
		int Next = vecRevTree[Cur][i];

		if (Check[Next])
			continue;

		Check[Next] = true;
		++Cnt;
		DFSRev(Next, Cnt);
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vecTree.resize(N + 1);
	vecRevTree.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;

		vecTree[Src].push_back(Dest);
		vecRevTree[Dest].push_back(Src);
	}

	for (int i = 1; i <= N; ++i)
	{
		Check[i] = true;
		int Cnt = 1;
		DFS(i, Cnt);
		DFSRev(i, Cnt);
		cout << N - Cnt << '\n';
		memset(Check, 0, N + 1);
	}

}

