
#include <iostream>

using namespace std;

int INF = 987654321;
int Connect[101][101] = {};

//플로이드-와샬 : 모든 쌍으로의 최단 경로 계산

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Connect[i][j];

			if (Connect[i][j] == 0)
				Connect[i][j] = INF;
		}
	}

	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (Connect[i][k] != INF
					&& Connect[k][j] != INF)
					Connect[i][j] = min(Connect[i][k] + Connect[k][j], Connect[i][j]);
			}
		}
	}
}
