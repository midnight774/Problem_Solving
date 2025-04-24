#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
BOJ 25418 정수 a를 k로 만들기
풀이 방법 : DP
*/

int DP[1000001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int A, K;
	cin >> A >> K;

	DP[A] = 1;

	for (int i = A + 1; i <= K; ++i)
	{
		DP[i] = DP[i - 1] + 1;

		if (i / 2 >= A && i % 2 == 0)
		{
			if (DP[i / 2] != 0)
				DP[i] = min(DP[i / 2] + 1, DP[i]);
		}	
	}

	cout << DP[K] - 1;
}


