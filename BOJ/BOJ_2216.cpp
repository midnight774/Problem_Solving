#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 2216 주사위 쌓기
풀이 방법 : 구현
*/

int Idx[6] = { 5,3,4,1,2,0 };
vector<vector<int>> vecDice;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		vector<int> vecNum(6);
		for (int j = 0; j < 6; ++j)
		{
			cin >> vecNum[j];
		}

		vecDice.push_back(vecNum);
	}

	int Max = 0;
	
	for (int i = 0; i < 6; ++i)
	{
		int TempSum = 0;
		int FloorIdx = i;

		for (int j = 0; j < N; ++j)
		{
			int MaxNum = 0;
			for (int k = 0; k < 6; ++k)
			{
				if (k == Idx[FloorIdx] || k == FloorIdx)
					continue;

				MaxNum = max(MaxNum, vecDice[j][k]);
			}

			TempSum += MaxNum;

			if (j + 1 == N)
				break;

			for (int k = 0; k < 6; ++k)
			{
				if (vecDice[j + 1][k] == vecDice[j][Idx[FloorIdx]])
				{
					FloorIdx = k;
					break;
				}
			}
		}

		Max = max(TempSum, Max);
	}

	cout << Max;
}

