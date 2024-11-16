#include <iostream>

using namespace std;

/*
BOJ 2228 구간 나누기
풀이 방법 : DP
*/

const int Min = -3276801;
int Num[101] = {};
int DP[101][51] = {};
bool Check[101][51] = {};

int TopDownDP(int n, int m)
{
	if (m == 0)
		return 0;

	if (n <= 0)
		return Min;

	if (Check[n][m])
		return DP[n][m];

	//현재 수를 구간에서 제외하는 경우
	DP[n][m] = TopDownDP(n - 1, m);

	int Sum = 0;
	for (int i = n; i >= 0; --i)
	{
		Sum += Num[i];

		//한칸 띄우고 최댓값 반영하여 최댓값 계산
		int NextSequence = TopDownDP(i - 2, m - 1) + Sum;
		DP[n][m] = max(DP[n][m], NextSequence);
	}

	Check[n][m] = true;
	return DP[n][m];
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Num[i];
	}

	int Answer = TopDownDP(N, M);
	cout << Answer;

}
