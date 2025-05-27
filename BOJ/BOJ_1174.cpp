
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
BOJ 1174번 줄어드는 수
풀이 방법 : 브루트포스
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	if (N <= 10)
	{
		cout << N - 1;
		return 0;
	}

	else if (N > 1023)
	{
		cout << -1;
		return 0;
	}

	//자릿수, 가장 왼쪽 수
	vector<vector<vector<string>>> vecNums;

	for (int i = 0; i <= 10; ++i)
	{
		vector<vector<string>> vecNew(10);
		vecNums.push_back(vecNew);
	}

	for (int i = 0; i < 10; ++i)
	{
		vecNums[1][i].push_back(to_string(i));
	}

	int CurCnt = 10;

	for (int i = 2; i <= 10; ++i)
	{
		for (int j = i - 1; j < 10; ++j)
		{
			for (int k = 0; k < j; ++k)
			{
				int Size = vecNums[i - 1][k].size();

				for (int l = 0; l < Size; ++l)
				{
					++CurCnt;

					if (CurCnt == N)
					{
						cout << j << vecNums[i - 1][k][l];
						return 0;
					}

					vecNums[i][j].push_back(to_string(j) + vecNums[i - 1][k][l]);
				}
			}
		}
	}
}

