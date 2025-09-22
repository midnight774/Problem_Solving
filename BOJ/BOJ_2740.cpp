#include <iostream>

using namespace std;

/*
BOJ 2740 행렬 곱셈
풀이 방법 : 분할 정복

A[l][i][j] = 행렬 A를 2^l 번 곱한 결과
*/

long long N, B;
int Origin[5][5] = {};
int A[38][5][5] = {};
int Ans[5][5] = {};

void MatSquare()
{
	for (int l = 1; l < 37; ++l)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				for (int k = 0; k < N; ++k)
				{
					A[l][i][j] += A[l - 1][i][k] * A[l - 1][k][j];
					A[l][i][j] %= 1000;
				}
			}
		}
	}
}

void MatMultiply(int Depth)
{
	int Tmp[5][5] = {};

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				Tmp[i][j] += A[Depth][i][k] * Ans[k][j];
				Tmp[i][j] %= 1000;
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Ans[i][j] = Tmp[i][j];
		}
	}

}


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> B;
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> A[0][i][j];
		}
	}

	

	MatSquare();
	for (int i = 0; i < N; ++i)
		Ans[i][i] = 1;

	int CurSq = 0;
	while (B > 0)
	{
		if (B % 2 == 1)
		{
			MatMultiply(CurSq);
		}

		B /= 2;
		++CurSq;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << Ans[i][j] << ' ';
		}
		cout << '\n';
	}


}

