#include <iostream>
#include <vector>

/*
BOJ 13023 ABCDE
풀이 방법 : 백트래킹
*/

using namespace std;

bool Check[2000] = {};
vector<vector<int>> vecFriend;
bool IsEnable = false;

void DFS(int CurNum, int CurDepth)
{
	if (IsEnable)
		return;

	if (CurDepth == 4)
	{
		IsEnable = true;
		return;
	}

	int Size = vecFriend[CurNum].size();

	for (int i = 0; i < Size; ++i)
	{
		int Dest = vecFriend[CurNum][i];

		if (Check[Dest])
			continue;

		Check[Dest] = true;
		DFS(Dest, CurDepth + 1);
		Check[Dest] = false;
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	
	vecFriend.resize(N);

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;
		vecFriend[Src].push_back(Dest);
		vecFriend[Dest].push_back(Src);
	}

	for (int i = 0; i < N; ++i)
	{
		Check[i] = true;
		DFS(i, 0);
		Check[i] = false;
	}

	cout << (int)IsEnable;
}
