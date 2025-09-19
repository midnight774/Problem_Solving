#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/*
BOJ 2213 트리의 독립집합
풀이 방법 : 트리에서의 DP + 역추적
*/

int Weight[10001] = {};
int DP[10001][2] = {};
bool Check[10001] = {};

vector<vector<int>> vecTree;
vector<int> vecAns;
int WeightSum = 0;

void DFS(int Node)
{
	DP[Node][0] = 0;
	DP[Node][1] = Weight[Node];

	int Size = vecTree[Node].size();
	for (int i = 0; i < Size; ++i)
	{
		int Next = vecTree[Node][i];
		if (Check[Next])
			continue;

		Check[Next] = true;

		DFS(Next);
		
		DP[Node][0] += max(DP[Next][1], DP[Next][0]);
		DP[Node][1] += DP[Next][0];
	}
}

void Trace(int Node, bool IsEnable)
{
	bool NextEnable = true;
	if(IsEnable)
	{
		if (DP[Node][0] < DP[Node][1])
		{
			vecAns.push_back(Node);
			NextEnable = false;
		}
	}

	int Size = vecTree[Node].size();
	for (int i = 0; i < Size; ++i)
	{
		int Next = vecTree[Node][i];
		if (Check[Next])
			continue;

		Check[Next] = true;
		Trace(Next, NextEnable);
	}
}


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vecVtx;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Weight[i];
	}

	vecTree.resize(N + 1);

	for (int i = 0; i < N - 1; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;

		vecTree[Src].push_back(Dest);
		vecTree[Dest].push_back(Src);
	}

	Check[1] = true;
	DFS(1);
	memset(Check, 0, N + 1);
	Check[1] = true;

	if (DP[1][0] < DP[1][1])
		Trace(1, true);

	else
		Trace(1, false);

	sort(vecAns.begin(), vecAns.end());
	cout << max(DP[1][0], DP[1][1]) << '\n';

	for (int i = 0; i < vecAns.size(); ++i)
		cout << vecAns[i] << ' ';
}

