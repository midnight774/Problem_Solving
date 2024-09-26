#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
백준 2463 - 비용
풀이 방법 : 유니온 파인드, 분리 집합

가중치가 큰 것부터 연결시켜가며 비용 계산
*/

const long long Mod = 1000000000;
int Root[100001] = {};
int CompSize[100001] = {};
long long Sum = 0;

struct Edge
{
	int Src;
	int Dest;
	long long Weight;
};

struct cmp
{
	bool operator() (const Edge& A, const Edge& B)
	{
		return A.Weight > B.Weight;
	}
};

int Find(int Num)
{
	if (Num == Root[Num])
		return Root[Num];

	Root[Num] = Find(Root[Num]);
	return Root[Num];
}

bool Union(int Src, int Dest)
{
	int SrcRoot = Find(Src);
	int DestRoot = Find(Dest);

	if (SrcRoot == DestRoot)
	{
		return true;
	}

	else
	{
		Root[SrcRoot] = DestRoot;
		return false;
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		Root[i] = i;
		CompSize[i] = 1;
	}

	vector<Edge> vecEdge(M);

	for (int i = 0; i < M; ++i)
	{
		cin >> vecEdge[i].Src >> vecEdge[i].Dest >> vecEdge[i].Weight;
	}

	sort(vecEdge.begin(), vecEdge.end(), cmp());
	vector<long long> vecSum(M);
	vecSum[M - 1] = vecEdge[M - 1].Weight;

	for (int i = M-2; i >= 0; --i)
	{
		vecSum[i] = vecEdge[i].Weight;
		vecSum[i] += vecSum[i + 1];
	}

	for (int i = 0; i < M; ++i)
	{
		int SrcParent = Find(vecEdge[i].Src);
		int DestParent = Find(vecEdge[i].Dest);

		if (SrcParent != DestParent)
		{
			int LeftCnt = CompSize[SrcParent]; int RightCnt = CompSize[DestParent];

			Root[SrcParent] = DestParent;
			CompSize[DestParent] += CompSize[SrcParent];
			Sum += vecSum[i] * LeftCnt * RightCnt;
			Sum %= Mod;
		}
	}

	cout << Sum;
}
