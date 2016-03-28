#include <iostream>

using namespace std;

bool isPowerOfThree(int num)
{
	if (num <= 0)
		return false;
	if (num > 1)
	{
		while (num % 3 == 0)
			num = num / 3;
	}
	if (num == 1)
		return true;
	else
		return false;
}

int main()
{
	cout << isPowerOfThree(0) << endl;
	cout << isPowerOfThree(2) << endl;
	cout << isPowerOfThree(3) << endl;
	cout << isPowerOfThree(4) << endl;
}