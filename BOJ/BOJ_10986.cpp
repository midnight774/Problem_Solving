#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 10986번 나머지 합
풀이 방법 : 누적 합
*/

int N, M;
int Sums[1000001] = {};
long long Cnt[1001] = {};
long long Answer = 0;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Sums[i];
		Sums[i] += Sums[i - 1];
		Sums[i] %= M;

		++Cnt[Sums[i]];
	}

	Answer += Cnt[0];

	for (int i = 0; i < M; ++i)
	{
		Answer += (Cnt[i] * (Cnt[i] - 1)) / 2;
	}

	cout << Answer;
}


