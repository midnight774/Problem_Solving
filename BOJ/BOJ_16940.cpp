#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

/*
백준 16940 BFS 스페셜 저지
풀이 방법 : BFS
*/

using namespace std;

int Cnt[100001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	vector<unordered_set<int>> vecGraph(N + 1);

	for (int i = 0; i < N - 1; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;
		++Cnt[Src];
		++Cnt[Dest];
		vecGraph[Src].insert(Dest);
		vecGraph[Dest].insert(Src);
	}

	vector<int> vecNum(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecNum[i];
	}

	bool Enable = true;
	
	int Start = 1;
	int Idx = 1;
	queue<int> qNode;
	qNode.push(Start);
	int CurCnt = 0;

	while (Idx < N)
	{
		if (qNode.empty())
			break;

		int Cur = qNode.front();

		if (CurCnt == Cnt[Cur])
		{
			CurCnt = 0;
			qNode.pop();
			continue;
		}

		if (vecGraph[Cur].find(vecNum[Idx]) != vecGraph[Cur].end())
		{
			--Cnt[vecNum[Idx]];
			vecGraph[vecNum[Idx]].erase(Cur);
			qNode.push(vecNum[Idx]);
			++CurCnt;
			++Idx;
		}

		else
		{
			qNode.pop();
			continue;
		}

	}

	if (Idx == N)
		cout << 1;

	else
		cout << 0;
}
