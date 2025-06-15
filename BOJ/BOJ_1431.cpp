#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 1431번 시리얼 번호
풀이 방법 : 정렬
*/

bool cmp(const string& Src, const string& Dest)
{
	int SrcLength = Src.length();
	int DestLength = Dest.length();

	if (SrcLength == DestLength)
	{
		int SrcSum = 0;
		int DestSum = 0;

		for (int i = 0; i < SrcLength; ++i)
		{
			int Num = (int)(Src[i] - '0');
			if (Num < 10 && Num >= 0)
				SrcSum += Num;

		}

		for (int i = 0; i < DestLength; ++i)
		{
			int Num = (int)(Dest[i] - '0');
			if (Num < 10 && Num >= 0)
				DestSum += Num;
		}

		if (SrcSum == DestSum)
		{
			return Src < Dest;
		}

		return SrcSum < DestSum;
	}

	return SrcLength < DestLength;


}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<string> vecSerial(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecSerial[i];
	}

	sort(vecSerial.begin(), vecSerial.end(), cmp);

	for (int i = 0; i < N; ++i)
	{
		cout << vecSerial[i] << '\n';
	}

}

