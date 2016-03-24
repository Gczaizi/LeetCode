#include <iostream>
#include <stdint.h>

using namespace std;

int hammingWeight(uint32_t n)
{
	uint32_t re = 0;
	uint32_t left = 0;
	while (n != 0)
	{
		left = n & 0x1; //�жϸ�λ�Ƿ�Ϊ 1
		re += left;		//��¼ 1 �ĸ���
		n = n >> 1;		//����һλ
	}
	return re;
}

int main()
{
	cout << hammingWeight(11) << endl;
	return 0;
}