#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
BOJ 19942번 다이어트
풀이 방법 : 브루트포스
*/

const int MaxPrice = 987654321;
int N;
int MinNutrient[4] = {};
int FoodInfo[16][5] = {};
int MinPrice = MaxPrice;
vector<int> Answer;


void DFS(int Depth, vector<int> vecInfo, vector<int> vecAns)
{
	bool Enable = true;

	if (vecInfo[4] <= MinPrice)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (vecInfo[i] < MinNutrient[i])
			{
				Enable = false;
				break;
			}

		}
	}

	else
		Enable = false;

	if (Enable)
	{
		Answer = vecAns;
		MinPrice = vecInfo[4];
		return;
	}

	if (Depth == N + 1)
		return;

	DFS(Depth + 1, vecInfo, vecAns);

	for (int i = 0; i < 5; ++i)
	{
		vecInfo[i] += FoodInfo[Depth][i];
	}

	vecAns.push_back(Depth);
	DFS(Depth + 1, vecInfo, vecAns);

}


int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < 4; ++i)
		cin >> MinNutrient[i];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> FoodInfo[i][j];
		}
	}
	
	vector<int> vecStartInfo(5);
	DFS(1, vecStartInfo, vector<int>());


	if (MinPrice == MaxPrice)
		cout << -1;

	else
	{
		cout << MinPrice << '\n';

		int Size = Answer.size();
		for (int i = 0; i < Size; ++i)
		{
			cout << Answer[i] << ' ';
		}
	}
}


