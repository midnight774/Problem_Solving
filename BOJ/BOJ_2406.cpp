#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* BOJ 2406 안정적인 네트워크 
* 풀이 방법 : MST
*/

int Root[1001] = {};
short Cost[1001][1001] = {};

struct CostInfo
{
	int Src;
	int Dest;
	int Cost;
};

struct cmp
{
	bool operator() (const CostInfo& Src, const CostInfo& Dest)
	{
		return Src.Cost < Dest.Cost;
	}
};

int Find(int Num)
{
	if (Root[Num] == Num)
	{
		return Root[Num];
	}

	Root[Num] = Find(Root[Num]);
	return Root[Num];
}

bool Union(int Src, int Dest)
{
	int SrcRoot = Find(Src);
	int DestRoot = Find(Dest);

	if (SrcRoot == DestRoot)
		return false;

	Root[SrcRoot] = DestRoot;
	return true;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		Root[i] = i;

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;
		Union(Src, Dest);
	}

	vector<CostInfo> vecCost;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			CostInfo Info;
			cin >> Info.Cost;

			if (i == 1)
				continue;

			if (j == 1)
				continue;

			if (i == j)
				continue;

			Info.Src = i;
			Info.Dest = j;

			vecCost.push_back(Info);
		}
	}

	sort(vecCost.begin(), vecCost.end(), cmp());

	int Sum = 0;
	int Count = 0;
	vector<pair<int, int>> vecEdge;

	int Size = vecCost.size();
	for (int i = 0; i < Size; ++i)
	{
		if (Union(vecCost[i].Src, vecCost[i].Dest))
		{
			Sum += vecCost[i].Cost;
			++Count;
			vecEdge.push_back(pair<int, int>(vecCost[i].Src, vecCost[i].Dest));
		}
	}
	
	cout << Sum << ' ' << Count << '\n';;
	for (int i = 0; i < Count; ++i)
	{
		cout << vecEdge[i].first << ' ' << vecEdge[i].second << '\n';
	}
}
