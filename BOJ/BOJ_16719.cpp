#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 16719 ZOAC
풀이 방법 : 재귀
*/

string Str;
bool Check[101] = {};

void Solve(int Cnt)
{
	int Length = Str.length();

	bool Enable = false;
	int CurNum = 28;
	int CurIdx = -1;

	for (int i = Length - 1; i >= 0; --i)
	{
		if (Check[i])
		{
			if (Enable)
				break;

			continue;
		}

		if (CurNum >= (int)(Str[i] - 'A'))
		{
			CurNum = (int)(Str[i] - 'A');
			CurIdx = i;
			Enable = true;
		}
	}

	Check[CurIdx] = true;
	string Temp = "";
	for (int i = 0; i < Length; ++i)
	{
		if (Check[i])
			Temp += Str[i];
	}

	cout << Temp << '\n';

	if (Cnt + 1 == Length)
		return;

	Solve(Cnt + 1);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> Str;
	
	Solve(0);

}

