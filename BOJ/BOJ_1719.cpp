#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 1719번 택배
풀이 방법 : 워셜 플로이드
*/

const int MaxTime = 987654321;
int Time[201][201] = {};
int Route[201][201] = {};


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
			Time[i][j] = MaxTime;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int Src, Dest, TimeCost;
		cin >> Src >> Dest >> TimeCost;

		Time[Src][Dest] = TimeCost;
		Time[Dest][Src] = TimeCost;

		Route[Src][Dest] = Dest;
		Route[Dest][Src] = Src;
	}
	
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (Time[i][k] == MaxTime || Time[k][j] == MaxTime)
					continue;

				if (Time[i][j] > Time[i][k] + Time[k][j])
				{
					Time[i][j] = Time[i][k] + Time[k][j];
					Route[i][j] = Route[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
				cout << '-';

			else
				cout << Route[i][j];

			cout << ' ';
		}
		cout << '\n';
	}
}


