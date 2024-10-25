#include <iostream>
#include <vector>

/*
BOJ 11501 주식
풀이 방법 : 그리디
*/

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T > 0)
	{
		--T;
		int N;
		cin >> N;

		vector<long long> vecNums(N);
		for (int i = 0; i < N; ++i)
			cin >> vecNums[i];

		long long CurMax = vecNums[N - 1];
		long long Answer = 0;

		for (int i = N - 2; i >= 0; --i)
		{
			CurMax = max(CurMax, vecNums[i]);
			Answer += max((long long)0, CurMax - vecNums[i]);
		}
	
		cout << Answer << '\n';
	}

}

