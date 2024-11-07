#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

/*
BOJ 1461 도서관
풀이 방법 : 그리디, 정렬
*/

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> vecPlus;
	vector<int> vecMinus;
	
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;

		if (Num > 0)
			vecPlus.push_back(Num);

		else
			vecMinus.push_back(Num);
	}

	int PlusSize = vecPlus.size();
	int MinusSize = vecMinus.size();

	sort(vecPlus.begin(), vecPlus.end());
	sort(vecMinus.begin(), vecMinus.end(), greater<>());

	int Sum = 0;

	int LeftIdx = 0;
	int LeftSize = MinusSize % M;
		
	if (LeftSize != 0)
	{
		Sum += abs(vecMinus[LeftIdx + (LeftSize - 1)]) * 2;
		LeftIdx += LeftSize;
	}

	for (int i = LeftIdx; i < MinusSize; i += M)
	{
		Sum += abs(vecMinus[i + M - 1]) * 2;
	}

	LeftIdx = 0;
	LeftSize = PlusSize % M;

	if (LeftSize != 0)
	{
		Sum += abs(vecPlus[LeftIdx + (LeftSize - 1)]) * 2;
		LeftIdx += LeftSize;
	}

	for (int i = LeftIdx; i < PlusSize; i += M)
	{
		Sum += abs(vecPlus[i + M - 1]) * 2;
	}

	int Max = 0;

	if (!vecPlus.empty())
		Max = max(vecPlus[PlusSize - 1], Max);

	if (!vecMinus.empty())
		Max = max(-vecMinus[MinusSize - 1], Max);

	Sum -= Max;

	cout << Sum;
}
