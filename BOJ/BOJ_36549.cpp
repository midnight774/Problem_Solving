#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 3649 로봇 프로젝트
풀이 방법 : 투 포인터
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int X, N;

	while (cin >> X)
	{
		if (cin.eof())
			break;

		cin >> N;
		X *= 10000000;

		vector<int> vecLego(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> vecLego[i];
		}

		sort(vecLego.begin(), vecLego.end());

		int Left = 0;
		int Right = N - 1;
		bool Enable = false;

		while (Left < Right)
		{
			int Sum = vecLego[Left] + vecLego[Right];
			if (Sum == X)
			{
				cout << "yes " << vecLego[Left] << ' ' << vecLego[Right] << '\n';
				break;
			}

			else if(Sum < X)
			{
				++Left;
			}

			else
			{
				--Right;
			}
		}

		if (Left >= Right)
			cout << "danger\n";

	}
}


