#include <iostream>
#include <set>

using namespace std;

/*
* 백준 1759 암호 만들기
* 풀이 방법 : 백트래킹
*/

int L, C;
bool Enable[27] = {};
set<string> setAnswer;

void DFS(string Cur, int Depth, int VowelCnt, int ConsonCnt)
{
	if (Cur.length() == L)
	{
		if (VowelCnt >= 1 && ConsonCnt >= 2)
		{
			setAnswer.insert(Cur);
		}

		return;
	}

	if (Depth == 26)
		return;

	DFS(Cur, Depth + 1, VowelCnt, ConsonCnt);

	if (Enable[Depth])
	{
		char NextChar = (char)(Depth + (int)'a');
		string Next = Cur + NextChar;
		int NextVowelCnt = VowelCnt;
		int NextConsonCnt = ConsonCnt;

		if (NextChar == 'a' || NextChar == 'e'
			|| NextChar == 'i' || NextChar == 'o'
			|| NextChar == 'u')
			++NextVowelCnt;

		else
			++NextConsonCnt;

		DFS(Next, Depth + 1, NextVowelCnt, NextConsonCnt);
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> L >> C;

	for (int i = 0; i < C; ++i)
	{
		char Alpha;
		cin >> Alpha;

		Enable[(int)(Alpha - 'a')] = true;
	}

	DFS("", 0, 0, 0);

	auto iter = setAnswer.begin();
	auto iterEnd = setAnswer.end();

	for (; iter != iterEnd; ++iter)
	{
		cout << *iter << '\n';
	}

}
