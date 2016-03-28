#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	if (nums.size() == 1)
		return nums[0];
	vector<int>dp(nums.size(), 0);
	dp[0] = nums[0];
	dp[1] = max(dp[0], nums[1]);
	for (int i = 2; i < nums.size(); i++)
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);		//×´Ì¬×ªÒÆ·½³Ì
	return dp[nums.size() - 1];
}

int main()
{
	vector<int>num{ 1, 2, 1, 2, 1, 2, 1, 2, 1, 2 };
	cout << rob(num) << endl;
}