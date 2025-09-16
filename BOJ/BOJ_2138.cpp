#include <iostream>

using namespace std;

/*
BOJ 2138 전구와 스위치
풀이 방법 : 그리디

	첫 번째 스위치를 누를지말지를 정하고 나면
	i번째 스위치는 i - 1번째 전구에 영향을 끼치는 유일한 트리거이다.
*/

int N;
int Ans = 987654321;

void SwitchOn(int Idx, string& Str)
{
	for (int i = Idx - 1; i <= Idx + 1; ++i)
	{
		if (i < 0 || i >= N)
			continue;

		Str[i] = Str[i] == '0' ? '1' : '0';
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	string Src, Dest;
	cin >> Src >> Dest;

	int Cnt = 0;

	string CurSrc = Src;

	for (int i = 1; i < N; ++i)
	{
		if (CurSrc[i - 1] != Dest[i - 1])
		{
			SwitchOn(i, CurSrc);
			++Cnt;
		}
	}

	if (CurSrc == Dest)
	{
		Ans = Cnt;
	}

	Cnt = 1;
	CurSrc = Src;

	SwitchOn(0, CurSrc);
	for (int i = 1; i < N; ++i)
	{
		if (CurSrc[i - 1] != Dest[i - 1])
		{
			SwitchOn(i, CurSrc);
			++Cnt;
		}
	}

	if (CurSrc == Dest)
	{
		Ans = min(Cnt, Ans);
	}

	if (Ans == 987654321)
		cout << -1;

	else
		cout << Ans;

}

