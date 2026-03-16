#include <iostream>

using namespace std;

/*
BOJ 2560 짚신벌레
풀이 방법 : 누적합

*/

const int Mod = 1000;
int BirthNum[1000001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b, d, N;
	cin >> a >> b >> d >> N;

	BirthNum[0] = 1;

	for (int i = 1; i <= N; ++i)
	{
		BirthNum[i] += BirthNum[i - 1] + Mod;
		BirthNum[i] %= Mod;

		int AdultDate = i - a;
		if (AdultDate < 0)
			continue;

		BirthNum[i] += BirthNum[AdultDate] + Mod;
		BirthNum[i] %= Mod;

		int SpawnDate = i - b;
		if (SpawnDate < 0)
			continue;

		BirthNum[i] -= BirthNum[SpawnDate] + Mod;
		BirthNum[i] %= Mod;
	}

	cout << (BirthNum[N] - BirthNum[N - d] + Mod) % Mod;
}




