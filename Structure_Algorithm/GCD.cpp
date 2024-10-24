#pragma once
class CEuclid
{
public:
	CEuclid() {}
	~CEuclid() {}

public:
	int GCD(int A, int B)
	{
		int Temp;

		if (A < B)
		{
			Temp = A;
			A = B;
			B = Temp;
		}

		int N = 0;

		while (B != 0)
		{
			N = A % B;
			A = B;
			B = N;
		}

		return A;
	}

	int LCM(int A, int B)
	{
		return (A * B) / GCD(A, B);
	}
};

