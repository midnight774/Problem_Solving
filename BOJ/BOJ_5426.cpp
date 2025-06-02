#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
BOJ 5426번 비밀 편지
풀이 방법 : 문자열
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	while(N> 0)
	{
		--N;

		string Input;
		cin >> Input;

		int Length = Input.length();

		int W = sqrt(Length);
		
		string Origin = "";
		for (int i = W - 1; i >=0; --i)
		{
			for (int j = 0; j < W; ++j)
			{
				int Idx = j * W + i;
				Origin += Input[Idx];
			}
		}
		
		cout << Origin << '\n';
	}

}

