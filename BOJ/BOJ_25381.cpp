
#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 25381번 ABBC
풀이 방법 : 그리디
*/


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	string Input;
	cin >> Input;
	
	int Length = Input.length();
	vector<int> vecIdx[3] = {};

	for (int i = 0; i < Length; ++i)
	{
		vecIdx[(int)(Input[i] - 'A')].push_back(i);
	}

	int Ans = 0;
	int BIdx = 0;
	int CIdx = 0;

	//C먼저 제거
	for (int i = 0; i < vecIdx[1].size(); ++i)
	{
		bool Enable = false;
		for (int j = CIdx; j < vecIdx[2].size(); ++j)
		{
			if (vecIdx[1][i] < vecIdx[2][j])
			{
				Enable = true;
				CIdx = j + 1;
				BIdx = i + 1;
				++Ans;
				break;
			}
		}

		if (!Enable)
			break;
	}
	
	//A,B 제거
	for (int i = 0; i < vecIdx[0].size(); ++i)
	{
		bool Enable = false;
		for (int j = BIdx; j < vecIdx[1].size(); ++j)
		{
			if (vecIdx[0][i] < vecIdx[1][j])
			{
				if (vecIdx[0][i] < vecIdx[1][j])
				{
					Enable = true;
					BIdx = j + 1;
					++Ans;
					break;
				}
			}
		}

		if (!Enable)
			break;
	}

	cout << Ans;
}

