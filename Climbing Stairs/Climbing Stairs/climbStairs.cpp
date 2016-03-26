#include <iostream>

using namespace std;

int climbStairs(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	int one_step_before = 2;	// n-1 的结果
	int two_step_before = 1;	// n-2 的结果
	int all = 0;

	for (int i = 2; i < n; i++)
	{
		all = one_step_before + two_step_before;
		two_step_before = one_step_before;
		one_step_before = all;
	}
	return all;
}

int main()
{
	int n;
	cin >> n;
	cout << climbStairs(n) << endl;

	return 0;
}