// https://open.kattis.com/problems/sumkindofproblem
// solution to open.kattis sum kind of problem

#include <iostream>
using namespace std;

int main()
{
	int P, K, N; // num data sets

	cin >> P;
	while(P-- > 0)	// perform while # data sets > 0
	{
		cin >> K >> N;
		cout << K << " " << (N * N + N)/2 << " " << N * N << " " << N * N + N << endl;
	}
}
