#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
백준 1647 도시 분할 계획
풀이 방법 : MST
*/

int Home[100001] = {};
int ConCnt = -1;

struct RoadInfo
{
	int Src;
	int Dest;
	int Cost;
};

struct cmp
{
	bool operator() (const RoadInfo& A, const RoadInfo& B)
	{
		return A.Cost < B.Cost;
	}
};

int FindRoot(int Num)
{
	if (Home[Num] == Num)
		return Home[Num];

	Home[Num] = FindRoot(Home[Num]);
	return Home[Num];
}

bool Union(int Src, int Dest)
{
	int SrcRoot = FindRoot(Src);
	int DestRoot = FindRoot(Dest);

	if (SrcRoot == DestRoot)
		return false;

	else
	{
		Home[SrcRoot] = Home[DestRoot];
		return true;
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	ConCnt = N;

	for (int i = 1; i <= N; ++i)
	{
		Home[i] = i;
	}

	vector<RoadInfo> vecRoad(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> vecRoad[i].Src >> vecRoad[i].Dest >> vecRoad[i].Cost;
	}

	sort(vecRoad.begin(), vecRoad.end(), cmp());
	long long Answer = 0;
	for (int i = 0; i < M; ++i)
	{
		if (ConCnt == 2)
			break;

		if (Union(vecRoad[i].Src, vecRoad[i].Dest))
		{
			Answer += vecRoad[i].Cost;
			--ConCnt;
		}

	}

	cout << Answer;
}
