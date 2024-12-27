#include <iostream>

/*
BOJ 14921 용액 합성하기
풀이 방법 : 투 포인터
*/

using namespace std;

int Liquid[100001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> Liquid[i];
	}


	int Left = 0;
	int Right = N - 1;
	int Sum = 2000000000;

	while (Left < Right)
	{
		int TempSum = Liquid[Left] + Liquid[Right];

		if (abs(Sum) > abs(TempSum))
		{
			Sum = TempSum;
		}

		if (TempSum < 0)
		{
			++Left;
		}

		else if (TempSum > 0)
		{
			--Right;
		}

		else
		{
			Sum = 0;
			break;
		}
	}

	cout << Sum;
}
