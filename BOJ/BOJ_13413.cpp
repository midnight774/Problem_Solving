#include <iostream>
#include <cmath>

using namespace std;

/*
BOJ 13413 오셀로 재배치
풀이 방법 : 그리디
*/

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

		string Src, Dest;
		cin >> Src >> Dest;

		int SrcBCnt = 0;
		int DestBCnt = 0;
		int DifferCnt = 0;

		for (int i = 0; i < N; ++i)
		{
			if (Src[i] == 'B')
				++SrcBCnt;


			if (Dest[i] == 'B')
				++DestBCnt;

			if (Src[i] != Dest[i])
				++DifferCnt;
		}

		int Ans = 0;
		Ans += abs(SrcBCnt - DestBCnt);
		Ans += (DifferCnt - abs(SrcBCnt - DestBCnt)) / 2;

		cout << Ans << '\n';

	}
}

