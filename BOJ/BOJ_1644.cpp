#include <iostream>
#include <vector>

/*
BOJ 1644 소수의 연속합
풀이 방법 : 투 포인터 + 에라토스테네스의 체 
*/

using namespace std;

bool Check[4000001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	Check[1] = true;
	vector<int> vecNum;

	for (int i = 2; i <= N; ++i)
	{
		int Num = i;

		if (Check[Num])
			continue;

		vecNum.push_back(i);

		Num += i;
		while (Num <= N)
		{
			Check[Num] = true;
			Num += i;
		}
	}

	int Left = 0;
	int Right = 0;
	int Max = vecNum.size();
	int Answer = 0;
	int CurNum = vecNum[0];

	while (Left <= Right && Left < Max && Right < Max)
	{
		if (CurNum == N)
		{
			++Answer;
		}

		if (CurNum > N)
		{
			CurNum -= vecNum[Left];
			++Left;
		}

		else
		{
			++Right;

			if (Right == Max)
				continue;

			CurNum += vecNum[Right];
		}
	}

	cout << Answer;
}

