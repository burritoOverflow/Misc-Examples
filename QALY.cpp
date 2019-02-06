// https://open.kattis.com/problems/qaly
// solution to open.kattis Quality Adjusted Life Year

#include <iostream>
using namespace std;

int main()
{
	int N;
	double q, y, total = 0.0;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> q >> y;
		total += (q * y);
	}

	cout << total;
}
