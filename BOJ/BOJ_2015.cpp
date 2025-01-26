#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

/*
BOJ 2015 수들의 합 4
풀이 방법 : 누적 합 + 해시
 */

using namespace std;

int Sum[200001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	unordered_map<int, long> mapSum;
	
	long Answer = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Sum[i];
		Sum[i] += Sum[i - 1];

		Answer += mapSum[Sum[i] - M];
		++mapSum[Sum[i]];
	}

	Answer += mapSum[M];

	cout << Answer;
}

