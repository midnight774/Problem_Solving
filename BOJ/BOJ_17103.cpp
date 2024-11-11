#include <iostream>
#include <vector>

/*
BOJ 17103 골드바흐 파티션
풀이 방법 : 에라토스테네스의 체
*/

using namespace std;

bool Check[1000001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<int> vecNums;

	for (int i = 2; i < 1000001; ++i)
	{
		if (Check[i])
			continue;

		vecNums.push_back(i);

		int Num = i + i;
		while (Num < 1000001)
		{
			Check[Num] = true;
			Num += i;
		}
	}

	int T;
	cin >> T;

	while (T > 0)
	{
		--T;

		int N;
		cin >> N;

		int Left = 0;
		int Right = vecNums.size() - 1;

		int Sum = vecNums[Left] + vecNums[Right];
		int Answer = 0;

		while (Left <= Right)
		{
			if (Sum < N)
			{
				Sum -= vecNums[Left];
				++Left;
				Sum += vecNums[Left];
			}

			else
			{
				if (Sum == N)
					++Answer;

				Sum -= vecNums[Right];
				--Right;
				Sum += vecNums[Right];
			}
		}

		cout << Answer << '\n';
	}
}
