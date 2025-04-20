#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 14468 소가 길을 건너간 이유 2
풀이 방법 : 구현
*/

int PrevIdx[26] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	string Route;
	cin >> Route;

	int Answer = 0;
	int Length = Route.length();
	int CurCnt = 0;

	for (int i = 0; i < 26; ++i)
		PrevIdx[i] = -1;

	for (int i = 0; i < Length; ++i)
	{
		int Idx = (int)(Route[i] - 'A');

		if (PrevIdx[Idx] == -1)
		{
			PrevIdx[Idx] = i;
		}

		else
		{
			int TempCnt = 0;
			for (int j = PrevIdx[Idx] + 1; j < i; ++j)
			{
				int TempIdx = (int)(Route[j] - 'A');
				if (PrevIdx[TempIdx] != -1)
					++TempCnt;
			}

			Answer += TempCnt;
			PrevIdx[Idx] = -1;
		}
		
	}

	cout << Answer;
	
}


