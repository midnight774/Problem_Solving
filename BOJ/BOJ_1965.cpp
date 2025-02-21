#include <iostream>
#include <vector>

/*
BOJ 1965 상자 넣기
풀이 방법 : DP
 */

using namespace std;

int DP[1001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> vecNum(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecNum[i];
	}

	DP[0] = 1;
	int Max = 1;
	for (int i = 1; i < N; ++i)
	{
		DP[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (vecNum[i] > vecNum[j])
			{
				DP[i] = max(DP[i], DP[j] + 1);
			}
			Max = max(Max, DP[i]);
		}
	}
	
	cout << Max;
}

