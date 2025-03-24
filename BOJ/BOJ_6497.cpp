#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 6497 전력난
풀이 방법 : MST
*/

int Root[200001] = {};

struct Info
{
	int Src;
	int Dest;
	int Dist;
};

struct cmp
{
	bool operator() (const Info& Src, const Info& Dest)
	{
		return Src.Dist < Dest.Dist;
	}
};

int Find(int Num)
{
	if (Num == Root[Num])
		return Num;

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

	while (true)
	{
		int N, M;
		cin >> N >> M;

		if (N == 0 && M == 0)
			break;

		for (int i = 0; i < N; ++i)
		{
			Root[i] = i;
		}

		vector<Info> vecInfo(M);
		int SumCost = 0;
		for (int i = 0; i < M; ++i)
		{
			cin >> vecInfo[i].Src >> vecInfo[i].Dest >> vecInfo[i].Dist;
			SumCost += vecInfo[i].Dist;
		}

		sort(vecInfo.begin(), vecInfo.end(), cmp());

		int CurCost = 0;

		for (int i = 0; i < M; ++i)
		{
			if (Union(vecInfo[i].Src, vecInfo[i].Dest))
			{
				CurCost += vecInfo[i].Dist;
			}
		}

		cout << SumCost - CurCost << '\n';
	}
}

