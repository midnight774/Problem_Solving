#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
BOJ 2295번 세 수의 합
풀이 방법 : Meet in the Middle
*/

int N;
unordered_set<long long> setCheck;
vector<long long> vecNum;
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	vecNum.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecNum[i];
		setCheck.insert(vecNum[i]);
	}

	sort(vecNum.begin(), vecNum.end());

	unsigned int Ans = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (vecNum[i] + vecNum[j] < vecNum[N - 1])
			{
				setCheck.insert(vecNum[i] + vecNum[j]);
			}
		}
	}

	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			auto iter = setCheck.find(vecNum[i] - vecNum[j]);

			if (iter != setCheck.end())
			{
				cout << vecNum[i];
				return 0;

			}
		}
	}
}

