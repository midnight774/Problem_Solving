#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 16398 행성 연결
풀이 방법 : MST
*/

int Root[1001] = {};
bool Check[1001][1001] = {};

struct Edge
{
	int Src;
	int Dest;
	long long Cost;
};

bool LessCost(const Edge& Src, const Edge& Dest)
{
	return Src.Cost < Dest.Cost;
}

int FindRoot(int Num)
{
	if (Root[Num] == Num)
		return Root[Num];

	Root[Num] = FindRoot(Root[Num]);
	return Root[Num];
}

bool Union(int Src, int Dest)
{
	int SrcRoot = FindRoot(Src);
	int DestRoot = FindRoot(Dest);

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

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		Root[i] = i;

	vector<Edge> vecGraph;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Edge Cur;
			Cur.Src = i;
			Cur.Dest = j;

			cin >> Cur.Cost;
			if (i == j)
				continue;

			if (Check[i][j])
				continue;

			Check[i][j] = true;
			Check[j][i] = true;

			vecGraph.push_back(Cur);
		}
	}

	sort(vecGraph.begin(), vecGraph.end(), LessCost);

	int Size = vecGraph.size();
	long long Ans = 0;

	for (int i = 0; i < Size; ++i)
	{
		if (Union(vecGraph[i].Src, vecGraph[i].Dest))
		{
			Ans += vecGraph[i].Cost;
		}
	}
	
	cout << Ans;
}

