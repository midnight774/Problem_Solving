#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
BOJ 17299 오등큰수
풀이 방법 : 스택
*/

int Cnt[1000001] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vecNum(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecNum[i];
		++Cnt[vecNum[i]];
	}

	vector<int> vecNGF(N);
	vecNGF[N - 1] = -1;

	stack<int> sNum;

	for (int i = N - 1; i >= 0; --i)
	{
		if (sNum.empty())
		{
			vecNGF[i] = -1;
			sNum.push(vecNum[i]);
		}

		else
		{
			while (!sNum.empty())
			{
				int Idx = sNum.top();
				if (Cnt[vecNum[i]] < Cnt[Idx])
				{
					vecNGF[i] = Idx;
					sNum.push(vecNum[i]);
					break;
				}

				else
				{
					sNum.pop();
					
					if (sNum.empty())
					{
						sNum.push(vecNum[i]);
						vecNGF[i] = -1;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
		cout << vecNGF[i] << ' ';

}

