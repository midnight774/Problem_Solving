#include <iostream>
#include <vector>
#include <algorithm>

/*
BOJ 1368 물대기
풀이 방법 : MST
다 따로따로 우물을 파놓은 상태에서부터 시작해서 
연결 비용이 가장 작은 것부터 탐색하며
최소 스패닝 트리 구성
이때 연결하는게 기존의 비용보다 더 드는 경우를 고려하면서 union 처리 해줘야 한다.
 */

using namespace std;

int N;
int Answer = 0;
int Root[301] = {};
int CostNew[301] = {};
bool Check[301][301] = {};

struct Edge
{
	int Src;
	int Dest;
	int Cost;
};

struct cmp
{
	bool operator() (const Edge& A, const Edge& B)
	{
		return A.Cost < B.Cost;
	}
};

int Find(int Num)
{
	if (Num == Root[Num])
		return Root[Num];

	Root[Num] = Find(Root[Num]);
	return Root[Num];
}

bool Union(int Src, int Dest, int ConnectCost)
{
	int SrcParent = Find(Src);
	int DestParent = Find(Dest);

	if (SrcParent == DestParent)
		return false;

	if (CostNew[SrcParent] + CostNew[DestParent] 
    <= min(CostNew[SrcParent], CostNew[DestParent]) + ConnectCost)
		return false;

	if (CostNew[SrcParent] < CostNew[DestParent])
	{
		Answer -= CostNew[DestParent];
		CostNew[DestParent] = CostNew[SrcParent];
	}

	else
	{
		Answer -= CostNew[SrcParent];
		CostNew[SrcParent] = CostNew[DestParent];
	}

	Answer += ConnectCost;
	Root[SrcParent] = Root[DestParent];

	return true;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> CostNew[i];
		Answer += CostNew[i];
		Root[i] = i;
	}

	vector<Edge> vecEdge;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int Num;
			cin >> Num;

			if (Check[i][j] || Check[j][i])
				continue;

			if (i == j)
				continue;

			Edge Cur;
			Cur.Src = i;
			Cur.Dest = j;
			Cur.Cost = Num;
			vecEdge.push_back(Cur);

			Check[j][i] = true;

		}
	}
	
	sort(vecEdge.begin(), vecEdge.end(), cmp());

	int Size = vecEdge.size();
	for (int i = 0; i < Size; ++i)
	{
		Union(vecEdge[i].Src, vecEdge[i].Dest, vecEdge[i].Cost);
	}
	

	cout << Answer;
}
