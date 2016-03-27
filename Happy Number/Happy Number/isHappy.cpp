#include <iostream>

using namespace std;

bool isHappy(int num)
{
	int sum = 0;
	int temp1, temp2;

	while (true)
	{
		do 
		{
			temp1 = num / 10;
			temp2 = num % 10;
			num = temp1;
			sum = sum + temp2 * temp2;
		} while (temp1 > 0);

		if (sum == 1)
			return true;
		else
		{
			if (sum == 4 || sum == 20 || sum == 16 || sum == 37 || sum == 42 || sum == 58 || sum == 89 || sum == 145)
				// unhappy number 数为平方和计算会进入
				// 4->16->37->58->89->145->42->20->4 的循环
				return false;
		}
		num = sum;
		sum = 0;
	}
}

int main()
{
	int num;
	cin >> num;
	cout << isHappy(num) << endl;
	return 0;
}