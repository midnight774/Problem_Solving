#include <iostream>
#include <cmath>

/* 
BOJ 1069 집으로
풀이 방법 : 기하
*/

using namespace std;

double Dist;
double MinTime;
int X, Y, D, T;

void GetMinTime(double CurDist, double CurTime)
{
	MinTime = min(MinTime, CurDist + CurTime);

	if (CurDist == 0.0)
		return;

	if (CurDist < D * 2)
		MinTime = min(MinTime, T * 2 + CurTime);

	if(CurTime + T <= MinTime)
		GetMinTime(abs(CurDist - D), CurTime + T);
	
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> X >> Y >> D >> T;

	Dist = sqrt(X * X + Y * Y);
	MinTime = Dist;

	GetMinTime(Dist, 0.0);

	cout << fixed;
	cout.precision(9);
	cout << MinTime;
}
