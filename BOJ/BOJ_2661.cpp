#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
BOJ 2661 좋은수열
풀이 방법 : 재귀
*/

int N;
string Answer = "";

void DFS(int CurLength, string CurNum)
{
	if (!Answer.empty())
		return;

	if (CurLength == N)
	{
		Answer = CurNum;
		return;
	}

	for (int i = 1; i <= 3; ++i)
	{
		if (CurLength != 0)
		{
			if (CurNum[CurLength - 1] == (char)(i + (int)'0'))
				continue;
		}

		bool Enable = true;
		string NextNum = CurNum + to_string(i);

		for (int j = 2; j <= (CurLength + 1) / 2; ++j)
		{
			for (int k = 0; k < CurLength + 1 - j; ++k)
			{
				string Sub1 = NextNum.substr(k, j);
				string Sub2 = NextNum.substr(k + j, j);

				if (Sub1 == Sub2)
				{
					Enable = false;
					break;
				}
			}

			if (!Enable)
				break;
		}

		if (Enable)
			DFS(CurLength + 1, NextNum);
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	DFS(0, "");

	cout << Answer;
}


