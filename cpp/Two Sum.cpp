/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndices;
        for (int i = 0; i < nums.size(); i++) {
            numIndices[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int m = target - n;
            auto itr = numIndices.find(m);
            if (itr != numIndices.end() && itr->second != i) {
                return {i + 1, itr->second + 1};
            }
        }
        return {};
    }
};