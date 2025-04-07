#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

/*
BOJ 9177 단어 섞기
풀이 방법 : 
*/

bool Check[201][201] = {};

bool CheckCombination(int SrcIdx, int DestIdx, int CurLength,
	const string& Src, const string& Dest, const string& Target)
{
	if (CurLength == Target.length())
		return true;

	bool Enable = false;

	if (Src[SrcIdx] == Target[CurLength])
	{
		if(!Check[SrcIdx + 1][DestIdx])
		{
			Check[SrcIdx + 1][DestIdx] = true;
			Enable |= CheckCombination(SrcIdx + 1, DestIdx, CurLength + 1, Src, Dest, Target);
		}
	}

	if (Dest[DestIdx] == Target[CurLength])
	{
		if (!Check[SrcIdx][DestIdx + 1])
		{
			Check[SrcIdx][DestIdx + 1] = true;
			Enable |= CheckCombination(SrcIdx, DestIdx + 1, CurLength + 1, Src, Dest, Target);
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
		string Str[3] = {};
		for (int j = 0; j < 3; ++j)
		{
			cin >> Str[j];
		}

		bool Enable = CheckCombination(0, 0, 0, Str[0], Str[1], Str[2]);
		
		string Result = Enable ? "yes" : "no";

		cout << "Data set " << i + 1 << ": " << Result << '\n';
		memset(Check, 0, 201 * 201);
	}

}

