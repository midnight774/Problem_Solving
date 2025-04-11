#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
BOJ 2986 파스칼
풀이 방법 : 정수론(약수)
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int Root = sqrt(N);

	for (int i = 2; i <= Root; ++i)
	{
		if (N % i == 0)
		{
			cout << N - N / i;
			return 0;
		}
	}

	cout << N - 1;
	
}

