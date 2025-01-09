#include <iostream>
#include <vector>

/*
BOJ 1051 숫자 정사각형
풀이 방법 : 브루트 포스
 */

using namespace std;

string Rect[51] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> Rect[i];
	}

	int Min = min(N, M);
	int Max = 1;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			for (int k = 1; k < Min; ++k)
			{
				if (i + k >= N || j + k >= M)
					continue;

				if (Rect[i][j] == Rect[i + k][j]
					&& Rect[i][j] == Rect[i][j + k]
					&& Rect[i][j] == Rect[i + k][j + k])
				{
					Max = max(Max, (k + 1) * (k + 1));
				}
			}
		}
	}


	cout << Max;
}
