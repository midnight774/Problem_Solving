#include <iostream>

/*
BOJ 21318 피아노 체조
풀이 방법 : 누적 합
*/

using namespace std;

int Level[100001] = {};
int CntSum[100001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Level[i];
	}

	for (int i = 2; i <= N; ++i)
	{
		if (Level[i - 1] > Level[i])
		{
			++CntSum[i - 1];
		}

		CntSum[i] += CntSum[i - 1];
	}

	int Q;
	cin >> Q;

	while(Q > 0)
	{
		--Q;

		int x, y;
		cin >> x >> y;

		cout << CntSum[y - 1] - CntSum[x - 1] << '\n';
	}

}
