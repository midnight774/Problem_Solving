#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
BOJ 2866 문자열 잘라내기
풀이 방법 : 이분 탐색
*/

string Input[1001] = {};
string Next[1001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int R, C;
	cin >> R >> C;


	for (int i = 0; i < R; ++i)
	{
		cin >> Input[i];
	}

	for (int i = 0; i < C; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			Next[i] += Input[j][i];
		}
	}

	int Cnt = 0;
	int Idx = 1;
	int CurLength = Next[0].length();

	int Left = 0;
	int Right = CurLength - 1;
	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;
		unordered_set<string> setCheck;

		bool Enable = true;
		for (int i = 0; i < C; ++i)
		{
			string Temp = Next[i].substr(Mid, CurLength - Mid);
			auto iter = setCheck.find(Temp);
			auto iterEnd = setCheck.end();

			if (iter == iterEnd)
			{
				setCheck.insert(Temp);
			}

			else
			{
				Enable = false;
				break;
			}
		}

		if (Enable)
		{
			Left = Mid + 1;
		}

		else
		{
			Right = Mid - 1;
		}
	}

	cout << Right;
}

