#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 20922 겹치는 건 싫어
풀이 방법 : 투 포인터
*/

int Cnt[100001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int Left = 0;
	int Right = 1;

	int Max = 1;

	vector<int> vecNum(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecNum[i];
	}

	++Cnt[vecNum[0]];

	while (Left <= Right && Right < N)
	{
		if (Cnt[vecNum[Right]] + 1 <= K)
		{
			++Cnt[vecNum[Right]];
			++Right;
		}

		else
		{
			--Cnt[vecNum[Left]];
			++Left;
		}

		Max = max(Max, Right - Left);
	}


	cout << Max;

}

