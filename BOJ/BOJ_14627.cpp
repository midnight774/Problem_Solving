#include <iostream>
#include <vector>

using namespace std;

/*
백준 14627 파닭파닭

풀이 방법 : 이분 탐색

*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int S, C;
	cin >> S >> C;
	
	vector<long long> vecGreen(S);
	long long Max = 0;
	for (int i = 0; i < S; ++i)
	{
		cin >> vecGreen[i];
		Max = max(vecGreen[i], Max);
	}

	long long Left = 1;
	long long Right = Max;

	long long ChickenGreen = 0;
	long long Ramen = 0;

	while (Left <= Right)
	{
		long long Mid = (Left + Right) / 2;

		long long ChickenCnt = 0;
		long long Sum = 0;

		for (int i = 0; i < S; ++i)
		{
			ChickenCnt += vecGreen[i] / Mid;
			Sum += vecGreen[i] - (vecGreen[i] % Mid);
		}

		if (ChickenCnt < C)
		{
			Right = Mid - 1;
		}

		else
		{
			Left = Mid + 1;
			ChickenGreen = Mid;
		}
	}
	
	long long Answer = 0;
	long long Cnt = 0;
	for (int i = 0; i < S; ++i)
	{
		if(Cnt < C)
		{
			long long TempNum = vecGreen[i];
			while (TempNum >= ChickenGreen)
			{
				TempNum -= ChickenGreen;
				++Cnt;

				if (Cnt == C)
					break;
			}

			Answer += TempNum;
		}

		else
		{
			Answer += vecGreen[i];
		}
					 
	}

	cout << Answer;
}
