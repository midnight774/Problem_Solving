#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
BOJ 1082 방 번호
풀이 방법 : DP
*/

int N, M;
int Price[10] = {};
string Num[51] = {};

string DP(int CurMoney, bool IsFirst)
{
	if (!Num[CurMoney].empty())
		return Num[CurMoney];

	string Max = "";
	string CurNum = "";

	for (int i = N - 1; i >= 0; --i)
	{
		if (IsFirst && i == 0)
			continue;

		if (CurMoney - Price[i] < 0)
			continue;

		CurNum = to_string(i) + DP(CurMoney - Price[i], false);
		
		if (CurNum.length() > Max.length())
			Max = CurNum;

		else if (CurNum.length() == Max.length())
			Max = max(CurNum, Max);
	}

	Num[CurMoney] = Max;
	return Max;

}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> Price[i];

	cin >> M;

	string Answer = DP(M, true);
	if (Answer.empty())
		cout << 0;

	else
		cout << Answer;
}

