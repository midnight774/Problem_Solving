#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 22115 창영이와 커피
풀이 방법 : DP

*/

int Caffein[100001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector<int> vecCaf(N);

	for (int i = 0; i < N; ++i)
		cin >> vecCaf[i];

	if (K == 0)
	{
		cout << 0;
		return 0;
	}

	for (int j = 1; j < 100001; ++j)
	{
		Caffein[j] = 987654321;
	}


	sort(vecCaf.begin(), vecCaf.end(), greater<>());
	Caffein[vecCaf[0]] = 1;
	Caffein[0] = 0;

	for (int i = 1; i < N; ++i)
	{
		for (int j = 100000; j >=0 ; --j)
		{
			if (j - vecCaf[i] < 0)
				continue;

			if (Caffein[j - vecCaf[i]] != 987654321)
				Caffein[j] = min(Caffein[j - vecCaf[i]] + 1, Caffein[j]);
		}
	}

	if (Caffein[K] == 987654321)
		cout << -1;

	else
		cout << Caffein[K];
}



