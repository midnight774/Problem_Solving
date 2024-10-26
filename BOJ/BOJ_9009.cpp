#include <iostream>
#include <vector>
#include <cmath>

/*
BOJ 9009 피보나치
풀이 방법 : 그리디
*/

using namespace std;

int Pib[45] = {};
bool Check[45] = {};

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	Pib[1] = 1;
	for (int i = 2; i <= 44; ++i)
	{
		Pib[i] = Pib[i - 1] + Pib[i - 2];
	}

	for (int i = 0; i < T; ++i)
	{
		int Num;
		cin >> Num;

		vector<int> vecAnswer;

		while (Num > 0)
		{
			for (int j = 44; j >= 2; --j)
			{
				if (Num >= Pib[j])
				{
					Num -= Pib[j];
					vecAnswer.push_back(Pib[j]);
					break;
				}
			}
		}

		int Size = vecAnswer.size();
		for (int j = Size - 1; j >= 0; --j)
			cout << vecAnswer[j] << ' ';

		cout << '\n';
	}

}

