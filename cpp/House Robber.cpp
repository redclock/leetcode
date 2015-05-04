/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/
class Solution {
public:
    int getmax(int a, int b) {
        return a > b ? a : b;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> maxMoney;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                maxMoney.push_back(nums[0]);
            }
            else if (i == 1) {
                maxMoney.push_back(getmax(nums[0], nums[1]));
            }
            else {
                int moneyIfRob = maxMoney[i - 2] + nums[i];
                int moneyIfNot = maxMoney[i - 1];
                maxMoney.push_back(getmax(moneyIfRob, moneyIfNot));
            }
        }
        return maxMoney[nums.size() - 1];
    }
};