#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
백준 11404 플로이드

풀이 방법 : 플로이드 - 워셜
*/

int Bus[101][101] = {};

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
			Bus[i][j] = 987654321;
		}
	}
	
	for (int i = 0; i < M; ++i)
	{
		int Src, Dest, Cost;
		cin >> Src >> Dest >> Cost;
	
		Bus[Src][Dest] = min(Cost, Bus[Src][Dest]);
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (Bus[i][k] == 987654321 || Bus[k][j] == 987654321)
					continue;

				Bus[i][j] = min(Bus[i][j], Bus[i][k] + Bus[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (Bus[i][j] == 987654321 || i == j)
				cout << 0 << ' ';

			else
				cout << Bus[i][j] << ' ';
		}

		cout << '\n';
	}
}
