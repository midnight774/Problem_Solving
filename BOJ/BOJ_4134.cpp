#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

/*
BOJ 4134 다음 소수
풀이 방법 : 브루트 포스

소수 사이 간격은 생각보다 작다
*/

bool IsPrime(unsigned int N)
{
	if (N <= 1)
		return false;

	for (unsigned int i = 2; i * i <= N; ++i)
	{
		if (N % i == 0)
			return false;
	}

	return true;
}

unsigned int NextPrime(unsigned int N)
{
	while (!IsPrime(N))
	{
		++N;
	}

	return N;
}


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

		unsigned int Num;
		cin >> Num;

		cout << NextPrime(Num) << '\n';
	}
	
}

