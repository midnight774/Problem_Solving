#include <iostream>

using namespace std;

string Src, Dest;
int Length = 0;
int AnswerIdx = -1;
int LCS[1001][1001] = {};

void FindLCS(int Y, int X, string& Answer)
{
	if (LCS[Y][X] == 0)
		return;

	if (LCS[Y][X] == LCS[Y][X - 1])
	{
		FindLCS(Y, X - 1, Answer);
		return;
	}

	if (LCS[Y][X] == LCS[Y - 1][X])
	{
		FindLCS(Y - 1, X, Answer);
		return;
	}

	Answer += Src[Y - 1];
	FindLCS(Y - 1, X - 1, Answer);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> Src >> Dest;

	int SLength = Src.length();
	int DLength = Dest.length();
	for (int i = 1; i <= SLength; ++i)
	{
		for (int j = 1; j <= DLength; ++j)
		{
			if (Src[i - 1] == Dest[j - 1])
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}

			else
			{
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}

			if (Length < LCS[i][j])
			{
				Length = LCS[i][j];
				AnswerIdx = i;
			}
		}
	}

	string Answer = "";

	int SIdx = SLength;
	int DIdx = DLength;

	FindLCS(SIdx, DIdx, Answer);

	cout << Length << '\n';

	for (int i = Length - 1; i >= 0; --i)
		cout << Answer[i];
}