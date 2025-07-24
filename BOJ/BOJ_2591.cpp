
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
BOJ 2591 숫자 카드
풀이 방법 : DP

두 자릿수에 대해 고려할 때 당연히 10 이상이어야 하는걸 잊고 헤매는 거에 주의
*/

string Input;
int DP[41] = {};


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> Input;

	int Length = Input.length();

	if (Length == 1)
	{
		cout << 1;
		return 0;
	}

	DP[1] = 1;

	int Start = stoi(Input.substr(0, 2));

	if (Start <= 34 && Start > 0)
		DP[2] = 1;

	if (stoi(Input.substr(1, 1)) != 0)
		DP[2] += 1;

	for (int i = 3; i <= Length; ++i)
	{
		int Idx = i - 1;
		int TenNum = stoi(Input.substr(Idx - 1, 2));
		int OneNum = stoi(Input.substr(Idx, 1));

		if (OneNum != 0)
		{
			DP[i] += DP[i - 1];
		}

		if (TenNum <= 34 && TenNum >= 10)
		{
			DP[i] += DP[i - 2];
		}
	}

	cout << DP[Length];
}

