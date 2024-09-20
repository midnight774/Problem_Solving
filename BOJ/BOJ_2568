#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	set<int> setAnswer;

	int N;
	cin >> N;

	vector<pair<int, int>> vecLine(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> vecLine[i].first >> vecLine[i].second;
	}

	sort(vecLine.begin(), vecLine.end());

	vector<int> vecNum;
	vecNum.push_back(vecLine[0].second);

	vector<int> vecIdx;
	vecIdx.push_back(0);

	for (int i = 1; i < N; ++i)
	{
		int Size = vecNum.size();
		if (vecNum[Size - 1] < vecLine[i].second)
		{
			vecNum.push_back(vecLine[i].second);
			vecIdx.push_back(Size);
		}

		else
		{
			int Left = 0;
			int Right = Size - 1;

			while (Left < Right)
			{
				int Mid = (Left + Right) / 2;

				if (vecNum[Mid] < vecLine[i].second)
				{
					++Left;
				}

				else
				{
					--Right;
				}
			}

			int Mid = (Left + Right) / 2;
			vecNum[Mid] = vecLine[i].second;
			vecIdx.push_back(Left);
		}
	}

	int Size = vecNum.size();
	cout << N - (Size) << '\n';
	
	int CurIdx = vecNum.size() - 1;
	vector<int> vecAnswer;
	for (int i = vecIdx.size() - 1; i >= 0; --i)
	{
		if (CurIdx == vecIdx[i])
		{
			--CurIdx;
		}

		else
		{
			vecAnswer.push_back(vecLine[i].first);
		}
	}

	sort(vecAnswer.begin(), vecAnswer.end());
	int AnsSize = vecAnswer.size();
	for (int i = 0; i < AnsSize; ++i)
	{
		cout << vecAnswer[i] << '\n';
	}

}
