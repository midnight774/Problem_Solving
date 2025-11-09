#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

/*
BOJ 18119 단어 암기
풀이 방법 : 비트마스킹
*/

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<bitset<26>> CheckStr(N);
	bitset<26> CheckBit;
	
	for (int i = 0; i < 26; ++i)
	{
		CheckBit[i] = 1;
	}

	for (int i = 0; i < N; ++i)
	{
		string Word;
		cin >> Word;
		int Length = Word.length();
		int CurNum = 0;

		for (int j = 0; j < Length; ++j)
		{
			CheckStr[i][(int)(Word[j] - 'a')] = 1;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int Q; char Alpha;

		cin >> Q >> Alpha;

		if (Q == 1)
		{
			bitset<26> EraseBit;
			EraseBit[(int)(Alpha - 'a')] = 1;
			EraseBit.flip();

			CheckBit &= EraseBit;
		}

		else
		{

			bitset<26> InsertBit;
			InsertBit[(int)(Alpha - 'a')] = 1;

			CheckBit |= InsertBit;

		}

		int Cnt = 0;
		for (int j = 0; j < N; ++j)
		{
			bitset<26> Check = CheckBit & CheckStr[j];
			if (Check == CheckStr[j])
				++Cnt;
		}
		
		cout << Cnt << '\n';
	}
}

