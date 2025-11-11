#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 2073 수도배관공사
풀이 방법 : DP, 배낭
*/

int DP[100001] = {};

struct Info
{
	int L;
	int C;
};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int D, P;
	cin >> D >> P;
	
	vector<Info> vecInfo(P);
	for (int i = 0; i < P; ++i)
	{
		cin >> vecInfo[i].L >> vecInfo[i].C;
	}

	DP[0] = 987654321;

	for (int i = 0; i < P; ++i)
	{
		int Cur = vecInfo[i].L;
		for (int j = D; j >= Cur; --j)
		{
			if (DP[j - Cur] == 0)
				continue;

			DP[j] = max(min(DP[j - Cur], vecInfo[i].C), DP[j]);
		}
	}
	
	cout << DP[D];
}


