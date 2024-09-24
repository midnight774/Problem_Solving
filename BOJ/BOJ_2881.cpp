#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int Max = 1000000001;
int DP[1001] = {};
vector<int> vecName;

int DFS(int Depth)
{
	if (DP[Depth] != Max)
		return DP[Depth];

	int Left = max(Depth + 1, 0);

	int Cnt = M - vecName[Depth];
	for (int i = Left; i <= N; ++i)
	{
		if (i == N)
		{
			DP[Depth] = 0;
			break;
		}

		DP[Depth] = min(DP[Depth], Cnt * Cnt + DFS(i));
		Cnt -= vecName[i] + 1;

		if (Cnt < 0)
			break;
	}

	return DP[Depth];
}


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	vecName.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecName[i];
		DP[i] = Max;
	}

	DP[N - 1] = 0;

	DFS(0);

	cout << DP[0];
}
