#include <iostream>
#include <string>
#include <unordered_set>

/*
BOJ 1283 단축키 지정
풀이 방법 : 구현
 */

using namespace std;

unordered_set<char> setStr;

int GetShortKeyIdx(const string& Str)
{
	int FirstIdx = 0;
	for (int i = 0; i <= Str.length(); ++i)
	{
		if (Str[i] == ' ' || i == Str.length())
		{
			char lower = tolower(Str[FirstIdx]);
			auto iter = setStr.find(lower);
			auto iterEnd = setStr.end();

			if (iter == iterEnd)
			{
				setStr.insert(lower);
				return FirstIdx;
			}

			else
			{
				FirstIdx = i + 1;
			}
		}
	}

	for (int i = 0; i < Str.length(); ++i)
	{
		if (Str[i] == ' ')
			continue;

		char lower = tolower(Str[i]);

		auto iter = setStr.find(lower);
		auto iterEnd = setStr.end();

		if (iter == iterEnd)
		{
			setStr.insert(lower);
			return i;
		}
	}

	return -1;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	cin.ignore();
	for (int i = 0; i < N; ++i)
	{
		string Input;

		getline(cin, Input);

		int Idx = GetShortKeyIdx(Input);

		if (Idx == -1)
			cout << Input << '\n';

		else
		{
			string Answer = "";

			Answer = Input.substr(0, Idx);
			Answer += '[';
			Answer += Input[Idx];
			Answer += ']';
			Answer += Input.substr(Idx + 1, Input.length() - Idx - 1);
			cout << Answer << '\n';
		}

	}
}

