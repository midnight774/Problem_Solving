#include <iostream>

using namespace std;

/*
BOJ 17609 회문
풀이 방법 : 투 포인터
*/

bool IsCom(int Left, int Right, const string& str)
{
	bool Enable = true;
	int Mid = (Right + Left) / 2;
	
	for (int i = 0; i <= Mid - Left; ++i)
	{
		if (str[i + Left] != str[Right - i])
		{
			Enable = false;
			break;
		}
	}

	return Enable;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		int Length = str.length();

		int Mid = Length / 2;

		bool Enable = true;
		int Cnt = 2;

		for (int i = 0; i <= Mid; ++i)
		{
			if (str[i] != str[Length - i - 1])
			{
				Enable = false;

				if (IsCom(i, Length - i - 2, str))
				{
					Cnt = 1;
					break;
				}

				if (IsCom(i + 1, Length - i - 1, str))
				{
					Cnt = 1;
					break;
				}

				break;
			}
		}

		if (Enable)
			cout << 0 << '\n';

		else
		{
			cout << Cnt<<'\n';
		}
	}

}
