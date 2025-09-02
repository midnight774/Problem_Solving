#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
BOJ 4803 트리
풀이 방법 : 유니온 파인드
이미 사이클이 발생한 그래프와 다른 트리와 연결할 때의 사이클 처리해줘야함
*/

int Root[501] = {};
bool IsCycle[501] = {};
bool IsCheck[501] = {};

int Find(int Num)
{
	if (Root[Num] == Num)
		return Root[Num];

	Root[Num] = Find(Root[Num]);
	return Root[Num];
}

void Union(int Src, int Dest)
{
	bool Cycle = false;
	int SrcRoot = Find(Src);
	int DestRoot = Find(Dest);

	if (SrcRoot == DestRoot)
	{
		IsCycle[SrcRoot] = true;
		return;
	}

	if (IsCycle[SrcRoot])
	{
		IsCycle[DestRoot] = true;
	}

	Root[SrcRoot] = DestRoot;
	return;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int CaseNum = 1;
	while (true)
	{
		int N, M;
		cin >> N >> M;

		if (N == 0 && M == 0)
			break;

		for (int i = 1; i <= N; ++i)
		{
			IsCheck[i] = false;
			IsCycle[i] = false;
			Root[i] = i;
		}

		for (int i = 0; i < M; ++i)
		{
			int Src, Dest;
			cin >> Src >> Dest;

			Union(Src, Dest);
		}

		int Cnt = 0;
		for (int i = 1; i <= N; ++i)
		{
			int CurRoot = Find(i);
			
			if (IsCheck[CurRoot])
				continue;

			IsCheck[CurRoot] = true;

			if (!IsCycle[CurRoot])
				++Cnt;
		}

		cout << "Case " << CaseNum << ": ";

		if (Cnt == 0)
			cout << "No trees.\n";

		else if(Cnt == 1)
			cout << "There is one tree.\n";

		else
			cout << "A forest of " << Cnt << " trees.\n";;
		
		++CaseNum;
	}

}

