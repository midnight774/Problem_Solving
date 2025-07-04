#include <iostream>

using namespace std;

/*
BOJ 16507번 어두운 건 무서워
풀이 방법 : 누적 합
*/

int Sum[1001][1001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int R, C, Q;
	cin >> R >> C >> Q;

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			cin >> Sum[i][j];
			Sum[i][j] += Sum[i][j - 1];

		}

		for (int j = 1; j <= C; ++j)
		{
			Sum[i][j] += Sum[i - 1][j];
		}
	}

	for (int i = 0; i < Q; ++i)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		int Sums = Sum[r2][c2] - Sum[r2][c1 - 1] - Sum[r1 - 1][c2] + Sum[r1 - 1][c1 - 1];
		int Cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
		cout << Sums / Cnt << '\n';
	}
	
}

