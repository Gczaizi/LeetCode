#include <iostream>
#include <stdint.h>

using namespace std;

int hammingWeight(uint32_t n)
{
	uint32_t re = 0;
	uint32_t left = 0;
	while (n != 0)
	{
		left = n & 0x1; //判断该位是否为 1
		re += left;		//记录 1 的个数
		n = n >> 1;		//右移一位
	}
	return re;
}

int main()
{
	cout << hammingWeight(11) << endl;
	return 0;
}