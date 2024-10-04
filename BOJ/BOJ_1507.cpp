#include <iostream>

using namespace std;

/*
백준 1507 궁금한 민호
풀이 방법 : 플로이드 - 워셜
*/

int Time[21][21] = {};
bool Check[21][21] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> Time[i][j];
		}
	}

	if (N == 1)
	{
		cout << 0;
		return 0;
	}
	
	bool Enable = true;

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (i == k || i == j || j == k)
					continue;

				if (Time[i][j] == Time[i][k] + Time[k][j])
				{
					Check[i][j] = true;
				}

				else if (Time[i][j] > Time[i][k] + Time[k][j])
				{
					Enable = false;
				}
				
			}
		}
	}

	int Sum = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if(!Check[i][j])
				Sum += Time[i][j];
		}
	}

	if (!Enable)
		cout << -1;

	else
		cout << Sum / 2;

}
