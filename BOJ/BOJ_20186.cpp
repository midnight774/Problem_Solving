#include <iostream>
#include <vector>
#include <algorithm>

/*
BOJ 20186 수 고르기
풀이 방법 : 정렬
 */

using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector<int> vecNum(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecNum[i];
	}
	
	int Minus = 0;
	for (int i = 1; i < K; ++i)
	{
		Minus += i;
	}
	
	int Sum = 0;
	sort(vecNum.begin(), vecNum.end(), greater<>());
	for (int i = 0; i < K; ++i)
	{
		Sum += vecNum[i];
	}

	cout << Sum - Minus;

}
