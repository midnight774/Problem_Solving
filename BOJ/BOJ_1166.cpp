#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
BOJ 1166번 선물
풀이 방법 : 이분 탐색
*/


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);


	double N, L, W, H;
	cin >> N >> L >> W >> H;

	double Left = 0;
	double Right = min(L, min(W, H));

	double Answer = 0;

	int  Cnt  = 100;
	while (Cnt > 0)
	{
		--Cnt;
		double Mid = (Left + Right) / 2;
		long long BoxCnt = floor(L / Mid) * floor(W / Mid) * floor(H / Mid);
		
		if (BoxCnt < N)
		{
			Right = Mid ;
		}

		else
		{
			Answer = Mid;
			Left = Mid;
		}
	}


	cout << fixed;
	cout.precision(10);
	
	cout << Left;
}


