#include <iostream>

/*
BOJ 1094 막대기
풀이 방법 : 수학 (이진수 1세기)
*/

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int Cnt = 0;

	while (N > 0)
	{
		if (N % 2 == 1)
			++Cnt;

		N /= 2;
	}

	cout << Cnt;
	
}
