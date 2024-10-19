#include <iostream>

/*
BOJ 1182 부분수열의 합
풀이 방법 : 백트래킹
*/

using namespace std;

int N, S;
int Num[21] = {};
int Answer = 0;

void DFS(int Depth, int CurSum, int NumCnt)
{
	if (Depth == N)
		return;

	DFS(Depth + 1, CurSum, NumCnt);

	if (CurSum + Num[Depth] == S)
	{
		++Answer;
	}

	DFS(Depth + 1, CurSum + Num[Depth], NumCnt + 1);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> S;

	for (int i = 0; i < N; ++i)
		cin >> Num[i];

	DFS(0, 0, 0);

	cout << Answer;
}
