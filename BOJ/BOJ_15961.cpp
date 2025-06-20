
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 15961번 회전 초밥
풀이 방법 : 슬라이딩 윈도우
*/

int Belt[3000001] = {};
int EatCnt[3001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, d, k, c;
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; ++i)
	{
		cin >> Belt[i];
	}

	int Max = 0;
	int Cnt = 0;

	for (int i = 0; i < k; ++i)
	{
		++EatCnt[Belt[i]];

		if (EatCnt[Belt[i]] == 1)
			++Cnt;
	}

	if(EatCnt[c] == 0)
		Max = max(Cnt + 1, Max);
	
	else
		Max = max(Cnt, Max);

	for (int i = 1; i < N; ++i)
	{
		int NextIdx = (i + k - 1) % N;

		--EatCnt[Belt[i - 1]];
		if (EatCnt[Belt[i - 1]] == 0)
			--Cnt;

		++EatCnt[Belt[NextIdx]];
		if (EatCnt[Belt[NextIdx]] == 1)
			++Cnt;

		if (EatCnt[c] == 0)
			Max = max(Cnt + 1, Max);

		else
			Max = max(Cnt, Max);
	}

	cout << Max;
}

