
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 8983번 사냥꾼
풀이 방법 : 이분 탐색
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int M, N, L;
	cin >> M >> N >> L;

	vector<int> vecFire(M);

	for (int i = 0; i < M; ++i)
	{
		cin >> vecFire[i];
	}

	vector<pair<int, int>> vecPos(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
	}

	int Cnt = 0;
	sort(vecFire.begin(), vecFire.end());

	for (int i = 0; i < N; ++i)
	{
		if (vecPos[i].second > L)
			continue;

		int Dist = L - vecPos[i].second;

		int Max = vecPos[i].first + Dist;
		int Min = max(1, vecPos[i].first - Dist);

		int Idx = lower_bound(vecFire.begin(), vecFire.end(), Min) - vecFire.begin();

		if (Idx >= vecFire.size())
			continue;

		if (vecFire[Idx] <= Max)
			++Cnt;
	}

	cout << Cnt;

}

