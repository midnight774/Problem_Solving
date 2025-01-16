#include <iostream>

/*
BOJ 16472 고냥이
풀이 방법 : 투 포인터
 */

using namespace std;

int Cnt[27] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	string Input;
	cin >> Input;

	
	int Length = Input.length();
	int Left = 0;
	int Right = 0;
	Cnt[(int)(Input[0] - 'a')] = 1;

	int Max = 1;
	int CurCnt = 1;

	while (Left <= Right && Right < Length && Left < Length)
	{
		if (CurCnt <= N)
		{
			Max = max(Max, Right - Left + 1);

			++Right;

			if (Right < Length)
			{
				if (Cnt[(int)(Input[Right] - 'a')] == 0)
					++CurCnt;

				++Cnt[(int)(Input[Right] - 'a')];

			}

			else
			{
				break;
			}

		}

		else
		{
			--Cnt[(int)(Input[Left] - 'a')];

			if (Cnt[(int)(Input[Left] - 'a')] == 0)
				--CurCnt;

			++Left;
		}
	}

	cout << Max;
}
