#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

/*
백준 17503 맥주 축제
풀이 방법 : 이분 탐색, 정렬
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	long long N, M, K;
	cin >> N >> M >> K;

	vector<pair<unsigned int, unsigned int>> vecBeer(K);
	for (int i = 0; i < K; ++i)
		cin >> vecBeer[i].first >> vecBeer[i].second;

	bool Enable = false;
	unsigned int Left = 0;
	unsigned int Right = INT_MAX;
	unsigned int Answer = INT_MAX;
	

	sort(vecBeer.begin(), vecBeer.end(), greater<>());

	while (Left <= Right)
	{
		unsigned int Mid = (Left + Right) / 2;

		unsigned int Sum = 0;
		int Cnt = 0;

		for (int i = 0; i < K; ++i)
		{
			if (vecBeer[i].second > Mid)
				continue;

			Sum += vecBeer[i].first;
			++Cnt;

			if (Cnt == N)
				break;
		}

		if (M <= Sum && Cnt == N)
		{
			Enable = true;
			Answer = min(Mid, Answer);
			Right = Mid - 1;
		}

		else
		{
			Left = Mid + 1;
		}
	}

	if (Enable)
		cout << Answer;

	else
		cout << -1;
}
