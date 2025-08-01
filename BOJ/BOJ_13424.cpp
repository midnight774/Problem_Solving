#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 13424 비밀 모임
풀이 방법 : 워셜 플로이드
*/

const int Inf = 987654321;

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

		int Cost[101][101] = {};
		int N, M;
		cin >> N >> M;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if(i != j)
					Cost[i][j] = Inf;
			}
		}

		for (int i = 0; i < M; ++i)
		{
			int Src, Dest, Dist;
			cin >> Src >> Dest >> Dist;

			Cost[Src][Dest] = Dist;
			Cost[Dest][Src] = Dist;
		}

		int FCnt;
		cin >> FCnt;

		vector<int> vecFriend(FCnt);
		for (int i = 0; i < FCnt; ++i)
			cin >> vecFriend[i];

		for (int k = 1; k <= N; ++k)
		{
			for (int i = 1; i <= N; ++i)
			{
				for (int j = 1; j <= N; ++j)
				{
					if (Cost[i][k] == Inf || Cost[k][j] == Inf)
						continue;

					Cost[i][j] = min(Cost[i][j], Cost[i][k] + Cost[k][j]);
				}
			}
		}

		int Num = -1;
		int Ans = Inf;

		for (int i = 1; i <= N; ++i)
		{
			int TempSum = 0;
			for (int j = 0; j < FCnt; ++j)
			{
				TempSum += Cost[i][vecFriend[j]];
			}

			if (Ans > TempSum)
			{
				Ans = TempSum;
				Num = i;
			}
		}

		cout << Num << '\n';
	}

}

