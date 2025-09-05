#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 8394 악수
풀이 방법 : DP
*/

//0이면 가장 뒤에꺼가 악수 안함

int DP[10000000][2] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	DP[2][0] = 1;
	DP[2][1] = 1;

	for (int i = 3; i <= N; ++i)
	{
		DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
		DP[i][0] %= 10;
		DP[i][1] = DP[i - 1][0];
		DP[i][1] %= 10;
	}

	cout << (DP[N][0] + DP[N][1]) % 10;

}

