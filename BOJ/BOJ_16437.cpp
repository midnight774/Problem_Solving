#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 16437 양 구출 작전
풀이 방법 : DFS
*/

vector<vector<int>> vecGraph;
long long CurCnt[123457] = {};
bool Check[123457] = {};

long long DFS(int CurIdx)
{
	int Size = vecGraph[CurIdx].size();

	for (int i = 0; i < Size; ++i)
	{
		int Next = vecGraph[CurIdx][i];

		if (Check[Next])
			continue;

		Check[Next] = true;
		CurCnt[CurIdx] += DFS(Next);
	}

	if (CurCnt[CurIdx] <= 0)
		return 0;

	return CurCnt[CurIdx];
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vecGraph.resize(N + 1);
	for (int i = 1; i < N; ++i)
	{
		char Info;
		int Cnt;
		int Dest;

		cin >> Info >> Cnt >> Dest;

		if (Info == 'S')
		{
			CurCnt[i + 1] = Cnt;
		}

		else
		{
			CurCnt[i + 1] = -Cnt;
		}

		vecGraph[Dest].push_back(i + 1);
	}

	Check[1] = true;
	DFS(1);
	cout << CurCnt[1];
}

