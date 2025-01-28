#include <iostream>
/*
BOJ 1300 K번째 수
풀이 방법 : 이분 탐색

Mid값 선택후 해당 값보다 작거나 같은 값들이 몇개인지 검사
 */

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	long long N, K;
	cin >> N >> K;
	
	long long Left = 1;
	long long Right = N * N;

	while (Left <= Right)
	{
		long long Mid = (Left + Right) / 2;
		long long Cnt = 0;

		for (int i = 1; i <= N; ++i)
		{
			Cnt += min(Mid / i, N);
		}

		if (K <= Cnt)
		{
			Right = Mid - 1;
		}

		else
		{
			Left = Mid + 1;
		}
	}

	cout << Left;
}

