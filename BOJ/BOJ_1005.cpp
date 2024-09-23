#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int InCnt[1001] = {};
int DP[1001] = {};
vector<int> vecTime;
vector<vector<int>> vecGraph;
int LTime = 0;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T > 0)
	{
		--T;
		int N, K;
		cin >> N >> K;

		vecTime.resize(N + 1);

		for (int i = 1; i <= N; ++i)
		{
			cin >> vecTime[i];
			InCnt[i] = 0;
		}

		vecGraph = vector<vector<int>>(N + 1);

		for (int i = 0; i < K; ++i)
		{
			int Src, Dest;
			cin >> Src >> Dest;
			vecGraph[Src].push_back(Dest);
			++InCnt[Dest];
		}

		int Last;
		cin >> Last;

		queue<int> qVtx;

		for (int i = 1; i <= N; ++i)
		{
			if (InCnt[i] == 0)
				qVtx.push(i);
		}

		for (int i = 1; i <= N; ++i)
		{
			DP[i] = -1;
		}

		vector<int> vecVtx;
		while (!qVtx.empty())
		{
			int Cur = qVtx.front();
			vecVtx.push_back(Cur);
			qVtx.pop();

			int Time = max(DP[Cur] + vecTime[Cur], vecTime[Cur]);

			int Size = vecGraph[Cur].size();

			for (int i = 0; i < Size; ++i)
			{
				--InCnt[vecGraph[Cur][i]];

				DP[vecGraph[Cur][i]] = max(DP[vecGraph[Cur][i]], Time);

				if (InCnt[vecGraph[Cur][i]] == 0)
					qVtx.push(vecGraph[Cur][i]);

			}
		}

		cout << max(DP[Last] + vecTime[Last], vecTime[Last]) << '\n';
		LTime = 0;

	}

}
