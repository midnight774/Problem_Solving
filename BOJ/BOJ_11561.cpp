#include <iostream>
#include <vector>

/*
BOJ 11561 징검다리
풀이 방법 : 이분탐색
 */

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	unsigned long long T;
	cin >> T;
	

	while (T > 0)
	{
		--T;

		unsigned long long N;
		cin >> N;

		unsigned long long Left = 1;
		unsigned long long Right = N;

		while (Left <= Right)
		{
			unsigned long long Mid = (Left + Right) / 2;

			unsigned long long Sum = (1 + Mid) * (Mid) / 2;

			if (Sum <= N)
			{
				Left = Mid + 1;
			}

			else
			{
				Right = Mid - 1;
			}
		}

		cout << Left - 1 << '\n';
	}
}

