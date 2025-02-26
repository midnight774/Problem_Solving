#include <iostream>
#include <stack>

using namespace std;

/*
백준 3986 좋은 단어
풀이 방법 : 스택
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	int Answer = 0;
	while (N > 0)
	{
		--N;
		string Input;
		cin >> Input;

		int Length = Input.length();

		if (Length % 2 == 1)
			continue;

		stack<char> sChar;
		for (int i = 0; i < Length; ++i)
		{
			if (sChar.empty())
			{
				sChar.push(Input[i]);
				continue;
			}

			if (sChar.top() == Input[i])
				sChar.pop();

			else
				sChar.push(Input[i]);
		}

		if (sChar.empty())
			++Answer;
		
	}

	cout << Answer;

}

