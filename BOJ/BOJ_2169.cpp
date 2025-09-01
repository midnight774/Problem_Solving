#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 2169 로봇 조종하기
풀이 방법 : DP

한 번 지난 칸은 다시 지날 수 없기에
내려온 뒤에 왼쪽으로 쭉 가거나 오른쪽으로 쭉 가거나 둘 중에 하나
양방향으로 DP테이블 만들어서 구하면 된다.
*/

int N, M;
int Table[1001][1001] = {};
int DP[1001][1001] = {};
int RevDP[1001][1001] = {};


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> Table[i][j];
			DP[i][j] = Table[i][j] + DP[i][j - 1];
			RevDP[i][j] = Table[i][j] + RevDP[i][j - 1];
		}
	}


	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			DP[i][j] = max(RevDP[i - 1][j] + Table[i][j], DP[i - 1][j] + Table[i][j]);
			RevDP[i][j] = DP[i][j];
		}

		for (int j = 2; j <= M; ++j)
		{
			DP[i][j] = max(DP[i][j], DP[i][j - 1] + Table[i][j]);
		}

		for (int j = M - 1; j >= 1; --j)
		{
			RevDP[i][j] = max(RevDP[i][j], RevDP[i][j + 1] + Table[i][j]);
		}
	}

	cout << DP[N][M];

}

