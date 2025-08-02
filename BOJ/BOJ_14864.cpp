#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 14864 서울에서 경산까지
풀이 방법 : DP
*/

int DP[101][100001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> vecTime(N);
	
	for (int i = 0; i < N; ++i)
	{
		int WT, WM, BT, BM;
		cin >> WT >> WM >> BT >> BM;
		vecTime[i].push_back(WT);
		vecTime[i].push_back(WM);
		vecTime[i].push_back(BT);
		vecTime[i].push_back(BM);
	}


	if (vecTime[0][0] <= K)
		DP[0][vecTime[0][0]] = vecTime[0][1];

	if(vecTime[0][2] <= K)
		DP[0][vecTime[0][2]] = max(DP[0][vecTime[0][2]], vecTime[0][3]);

	for (int i = 1; i < N; ++i)
	{
		int Limit = K - vecTime[i][0];

		for (int j = 0; j <= Limit; ++j)
		{
			if (DP[i - 1][j] != 0)
				DP[i][j + vecTime[i][0]] = max(DP[i][j + vecTime[i][0]], DP[i - 1][j] + vecTime[i][1]);
		}

		Limit = K - vecTime[i][2];
		for (int j = 0; j <= Limit; ++j)
		{
			if(DP[i - 1][j] != 0)
				DP[i][j + vecTime[i][2]] = max(DP[i][j + vecTime[i][2]], DP[i - 1][j] + vecTime[i][3]);
		}
	}

	int Ans = 0;
	for (int i = 3; i <= K; ++i)
	{
		Ans = max(Ans, DP[N - 1][i]);
	}

	cout << Ans;
}

