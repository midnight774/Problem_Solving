#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
백준 19951 태상이의 훈련소 생활 
풀이 방법 : 누적 합
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);


	int N, M;
	cin >> N >> M;

	vector<int> vecHeight(N + 2);

	for (int i = 1; i <= N; ++i)
	{
		cin >> vecHeight[i];
	}

	vector<int> vecMinus(N + 2);

	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vecMinus[a - 1] -= c;
		vecMinus[b] += c;
	}

	for (int i = 1; i <= N; ++i)
	{
		vecMinus[i] += vecMinus[i - 1];
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << vecHeight[i] - vecMinus[i - 1] << ' ';
	}
}
