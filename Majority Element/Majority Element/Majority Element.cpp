#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int majorityElement(vector<int>& num)
{
	int major = num[0];
	int count = 1;
	for (int i = 1; i < num.size(); i++)
	{
		if (count == 0)
		{
			count++;
			major = num[i];
		}
		else
		{
			if (major == num[i])
				count++;
			else
				count--;
		}
	}
	return major;
}

int main()
{
	vector<int> num = { 6, 6, 6, 7, 7 };
	cout << majorityElement(num) << endl;
	return 0;
}