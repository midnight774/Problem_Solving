#include <iostream>
#include <vector>
#include <algorithm>

/*
BOJ 16208 귀찮음
풀이 방법 : 정렬
 */

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vecNum(N);
	int Sum = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> vecNum[i];
		Sum += vecNum[i];
	}

	long long Cost = 0;

	sort(vecNum.begin(), vecNum.end());

	for (int i = 0; i < N; ++i)
	{
		Cost += vecNum[i] * (Sum - vecNum[i]);
		Sum -= vecNum[i];
	}

	cout << Cost;
}

