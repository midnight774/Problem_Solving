#include <iostream>

using namespace std;

/*
BOJ 2133 타일 채우기
풀이 방법 : DP
*/

int DP[31] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	if (N % 2 == 1)
	{
		cout << 0;
	}

	else
	{
		DP[0] = 1;
		for (int i = 2; i <= N; i += 2)
		{
			DP[i] += DP[i - 2] * 3;
			for (int j = 4; j <= i; j += 2)
			{
				DP[i] += DP[i - j] * 2;
			}
		}
		
		cout << DP[N];
		
	}

	
}

