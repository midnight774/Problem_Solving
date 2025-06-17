
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 1414번 불우이웃돕기
풀이 방법 : MST
*/

int Board[51][51] = {};
int Root[51] = {};

struct EdgeInfo
{
	int Src;
	int Dest;
	int Length;
};

bool cmp(const EdgeInfo& Src, const EdgeInfo& Dest)
{
	return Src.Length < Dest.Length;
}

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

	int Sum = 0;

	vector<EdgeInfo> vecEdge;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char Input;
			cin >> Input;

			if (Input == '0')
				continue;

			int Length = 0;

			if (Input - 'a' < 0)
			{
				Length = (int)(Input - 'A') + 27;
			}

			else
			{
				Length = (int)(Input - 'a') + 1;
			}

			vecEdge.push_back({ i,j,Length });
			Sum += Length;
		}
	}

	int Cnt = 0;
	int UsedLength = 0;

	sort(vecEdge.begin(), vecEdge.end(), cmp);
	int Size = vecEdge.size();
	for (int i = 0; i < Size; ++i)
	{
		if (Union(vecEdge[i].Src, vecEdge[i].Dest))
		{
			++Cnt;
			UsedLength += vecEdge[i].Length;
		}
	}

	if (Cnt == N - 1)
	{
		cout << Sum - UsedLength;
	}

	else
		cout << -1;

}

