#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
BOJ 10610 30
풀이 방법 : 그리디
*/

int Cnt[10] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	string Input;
	cin >> Input;

	int Length = Input.length();
	for (int i = 0; i < Length; ++i)
	{
		++Cnt[(int)(Input[i] - '0')];
	}

	if (Cnt[0] == 0)
	{
		cout << -1;
		return 0;
	}

	int Sum = 0;
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 0; j < Cnt[i]; ++j)
		{
			Sum += i;
		}
	}

	if (Sum % 3 != 0)
	{
		cout << -1;
		return 0;
	}

	string Answer = "";

	for (int i = 9; i >= 0; --i)
	{
		for(int j =0;j<Cnt[i];++j)
			Answer += to_string(i);
	}

	cout << Answer;

}

