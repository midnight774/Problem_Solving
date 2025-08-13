#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

/*
BOJ 20164 홀수 홀릭 호석
풀이 방법 : 
*/

string Input;
int Min = INT_MAX;
int Max = 0;

void CheckOdd(string Input, int Cnt)
{
	int Length = Input.length();

	int OddCnt = 0;
	for (int i = 0; i < Length; ++i)
	{
		if ((int)(Input[i] - '0') % 2 == 1)
			++OddCnt;
	}

	if (Input.length() == 1)
	{
		Min = min(Cnt + OddCnt, Min);
		Max = max(Cnt + OddCnt, Max);
		return;
	}

	else if(Input.length() == 2)
	{
		int Num = (int)(Input[0] - '0') + (int)(Input[1] - '0');
		string Next = to_string(Num);
		CheckOdd(Next, Cnt + OddCnt);
	}

	else
	{
		for (int i = 1; i < Length; ++i)
		{
			for (int j = i + 1; j < Length; ++j)
			{
				int Num = stoi(Input.substr(0, i))
					+ stoi(Input.substr(i, j - i))
					+ stoi(Input.substr(j, Length - j));

				string Next = to_string(Num);

				CheckOdd(Next, Cnt + OddCnt);
			}
		}
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> Input;
	CheckOdd(Input, 0);
	cout << Min << ' ' << Max;

}

