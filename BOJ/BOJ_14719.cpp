#include <iostream>
#include <vector>

using namespace std;

/*
BOJ 14719 빗물
풀이 방법 : 구현

정순으로 체크 한번, 역순으로 체크 한번
높이가 같은 경우를 두 번 체크하지 않도록 주의
*/


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int H, W;
	cin >> H >> W;

	vector<int> vecHeight(W);
	for (int i = 0; i < W; ++i)
	{
		cin >> vecHeight[i];
	}

	int Ans = 0;
	int CurMax = vecHeight[0];
	int MaxIdx = 0;
	for (int i = 0; i < W; ++i)
	{
		if (CurMax < vecHeight[i])
		{
			for (int j = MaxIdx + 1; j < i; ++j)
				Ans += CurMax - vecHeight[j];

			CurMax = vecHeight[i];
			MaxIdx = i;
		}
	}

	CurMax = vecHeight[W - 1];
	MaxIdx = W - 1;
	for (int i = W - 2; i >= 0; --i)
	{
		if (CurMax <= vecHeight[i])
		{
			for (int j = MaxIdx - 1; j > i; --j)
				Ans += CurMax - vecHeight[j];

			CurMax = vecHeight[i];
			MaxIdx = i;
		}
	}

	cout << Ans;

}

