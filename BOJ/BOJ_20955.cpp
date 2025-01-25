#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

/*
BOJ 20955 민서의 응급 수술
풀이 방법 : 분리 집합
 */

using namespace std;

int Root[100001] = {};
bool Check[100001] = { };

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
	int SrcParent = Find(Src);
	int DestParent = Find(Dest);

	if (SrcParent != DestParent)
	{
		Root[DestParent] = SrcParent;
		return true;
	}

	return false;
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

	int Cnt = 0;
	for (int i = 0; i < M; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;
		if (!Union(Src, Dest))
			++Cnt;
	}

	for (int i = 1; i <= N; ++i)
	{
		int Root = Find(i);

		if (Check[Root])
			continue;

		Check[Root] = true;
		++Cnt;
	}

	cout << Cnt - 1;
}

