#include <iostream>

/*
BOJ 5904 Moo 게임
풀이 방법 : 분할 정복
 */

using namespace std;

int Cnt[30] = {};

bool IsM(int CurNum)
{
	int Target = 0;
	for (int i = 0; i < 30; ++i)
	{
		if (CurNum <= Cnt[i])
		{
			Target = i;
			break;
		}
	}

	if (Target != 0)
		CurNum -= Cnt[Target - 1];

	if (CurNum > (Target + 3))
	{
		CurNum -= Target + 3;
	}

	else
	{
		if (CurNum == 1)
			return true;

		else
		{
			return false;
		}
	}

	return IsM(CurNum);

}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	Cnt[0] = 3;
	int TargetNum = 0;
	for (int i = 1; i < 30; ++i)
	{
		Cnt[i] = Cnt[i - 1] * 2 + i + 3;
	}


	bool bM = IsM(N);

	if (bM)
		cout << 'm';

	else
		cout << 'o';
}
