#include <iostream>

/*
BOJ 1058 친구
풀이 방법 : 브루트 포스
 */

using namespace std;

int N;
bool IsFriend[51][51] = {};
bool Check[51] = {};
int Max = 0;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string Input;
		cin >> Input;

		for (int j = 0; j < N; ++j)
		{
			if (Input[j] == 'Y')
				IsFriend[i][j] = true;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		int Cnt = 0;
		for (int j = 0; j < N; ++j)
		{
			if (i == j)
				continue;

			if (IsFriend[i][j])
			{
				++Cnt;
				continue;
			}

			for (int k = 0; k < N; ++k)
			{
				if (i == k || j == k)
					continue;

				if (IsFriend[i][k] && IsFriend[j][k])
				{
					++Cnt;
					break;
				}
			}
		}

		Max = max(Cnt, Max);
	}
	cout << Max;
}
