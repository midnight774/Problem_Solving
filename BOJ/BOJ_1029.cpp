#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
BOJ 1029 그림 교환
풀이 방법 : 비트마스킹
*/

int N;
string Info[15] = {};
int Price[15][15] = {};
int Ans = 1;
int DP[1 << 16 + 1][16][10] = {};

void DFS(int CurOwner, int CurPrice, int Cnt, int Bit)
{
	Ans = max(Ans, Cnt);

	for (int i = 0; i < N; ++i)
	{
		if (Bit & (1 << i))
			continue;

		if (Price[CurOwner][i] >= CurPrice)
		{
			int Next = (Bit | (1 << i));
			int NextPrice = Price[CurOwner][i];

			if (DP[Next][i][NextPrice] >= Cnt + 1)
				continue;

			DP[Next][i][NextPrice] = Cnt + 1;
			DFS(i, Price[CurOwner][i], Cnt + 1, Next);
		}
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Info[i];

		for (int j = 0; j < N; ++j)
		{
			Price[i][j] = (int)Info[i][j] - (int)'0';
		}
	}


	DFS(0, 0, 1, 1);
	cout << Ans;

}

