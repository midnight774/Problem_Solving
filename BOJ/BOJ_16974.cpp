#include <iostream>

/*
BOJ 16974 레벨 햄버거
풀이 방법 : DP + 재귀
*/

using namespace std;

long long WholeCnt[51] = {};
long long Cnt[51] = {};

long long Recursive(int Level, long long CurCnt)
{
	if (Level == 0)
		return 1;

	if (Level >= CurCnt)
		return 0;

	if (CurCnt == WholeCnt[Level] / 2 + 1)
	{
		return Cnt[Level - 1] + 1;
	}

	else if (CurCnt <= WholeCnt[Level] / 2)
	{
		return Recursive(Level - 1, CurCnt - 1);
	}

	else
	{
		return  Recursive(Level - 1, CurCnt - (WholeCnt[Level] / 2 + 1)) + Cnt[Level - 1] + 1;
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N; 
	long long X;
	cin >> N >> X;

	WholeCnt[0] = 1;
	Cnt[0] = 1;

	for (int i = 1; i <= 50; ++i)
	{
		WholeCnt[i] = WholeCnt[i - 1] * 2 + 3;
		Cnt[i] = Cnt[i - 1] * 2 + 1;
	}

	long long Answer = Recursive(N, X);

	cout << Answer;
}
