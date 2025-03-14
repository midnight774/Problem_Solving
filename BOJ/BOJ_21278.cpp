#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 21278 호석이 두 마리 치킨
풀이 방법 : 플로이드 워셜
*/

int Dist[101][101] = {};


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			Dist[i][j] = 201;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest;
		cin >> Src >> Dest;

		Dist[Src][Dest] = 1;
		Dist[Dest][Src] = 1;
	}

	int MinCost = 100001;
	int AnswerSrc = -1;
	int AnswerDest = -1;

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (Dist[i][k] == 201 || Dist[k][j] == 201)
					continue;

				Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
			}
		}
	}


	for (int i = 1; i <= N; ++i)
	{
		for (int j = i + 1; j <= N; ++j)
		{
			int Sum = 0;
			for (int k = 1; k <= N; ++k)
			{
				if (k == i || k == j)
					continue;

				Sum += min(Dist[i][k] * 2, Dist[j][k] * 2);
			}

			if (MinCost > Sum)
			{
				MinCost = Sum;
				AnswerSrc = i;
				AnswerDest = j;
			}
		}
	}

	cout << AnswerSrc << ' ' << AnswerDest << ' ' << MinCost;
}

