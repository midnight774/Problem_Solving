#include <iostream>
#include <vector>

/*
BOJ 19539 사과나무
풀이 방법 : 그리디
*/

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vecNum(N);
	int Sum = 0;
	int TwoCnt = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> vecNum[i];

		Sum += vecNum[i];
		TwoCnt += vecNum[i] / 2;
	}

	bool Enable = false;

	if (Sum % 3 == 0)
	{
		int DayCnt = Sum / 3;

		if (DayCnt <= TwoCnt)
		{
			Enable = true;
		}
	}


	if (Enable)
		cout << "YES";

	else
		cout << "NO";


}

