
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 1939번 중량제한
풀이 방법 : 분리 집합
*/

int Root[100001] = {};

struct Edge
{
	int Src;
	int Dest;
	int WeightMax;
};

bool Cmp(const Edge& Src, const Edge& Dest)
{
	return Src.WeightMax > Dest.WeightMax;
}

int Find(int Num)
{
	if (Root[Num] == Num)
		return Root[Num];

	Root[Num] = Find(Root[Num]);
	return Root[Num];
}

void Union(int Src, int Dest)
{
	int SrcRoot = Find(Src);
	int DestRoot = Find(Dest);

	if (SrcRoot == DestRoot)
		return;

	Root[SrcRoot] = DestRoot;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
		
	int N, M;
	cin >> N >> M;

	vector<Edge> vecEdge(M);

	for (int i = 0; i < M; ++i)
	{
		cin >> vecEdge[i].Src >> vecEdge[i].Dest >> vecEdge[i].WeightMax;
	}

	for (int i = 1; i <= N; ++i)
		Root[i] = i;

	int Src, Dest;
	cin >> Src >> Dest;

	sort(vecEdge.begin(), vecEdge.end(), Cmp);

	for (int i = 0; i < M; ++i)
	{
		Union(vecEdge[i].Src, vecEdge[i].Dest);

		if (Find(Src) == Find(Dest))
		{
			cout << vecEdge[i].WeightMax;
			break;
		}
	}

}

