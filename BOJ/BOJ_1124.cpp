#include <iostream>

/*
BOJ 1124 언더프라임
풀이 방법 : 소수 판정
*/

using namespace std;

bool Check[100001] = {};
int PrimeCnt[100001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int A, B;
	cin >> A >> B;

	int Answer = 0;

	Check[0] = true;
	Check[1] = true;

	for (int i = 2; i <= B; ++i)
	{
		int Num = i;
		if (Check[Num])
			continue;

		Num += i;

		while (Num <= B)
		{
			Check[Num] = true;

			int TempNum = Num;
			while (TempNum % i == 0)
			{
				++PrimeCnt[Num];
				TempNum /= i;
			}

			Num += i;
		}
	}

	for (int i = A; i <= B; ++i)
	{
		if (!Check[PrimeCnt[i]])
			++Answer;
	}

	cout << Answer;
}
