#include <iostream>
#include <vector>

/*
BOJ 1316 그룹 단어 체커
풀이 방법 : 구현
 */

using namespace std;


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int Answer = 0;

	for (int i = 0; i < N; ++i)
	{
		char Prev = '.';

		string Word;
		cin >> Word;

		int Length = Word.length();
		bool Enable = true;

		bool Check[26] = {};

		for (int j = 0; j < Length; ++j)
		{
			if (Prev != Word[j])
			{
				if (Check[(int)(Word[j] - 'a')])
				{
					Enable = false;
					break;
				}

				else
				{
					Check[(int)(Word[j] - 'a')] = true;
					Prev = Word[j];
				}
			}
		}

		if (Enable)
			++Answer;
	}

	cout << Answer;
}
