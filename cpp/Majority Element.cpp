/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
class Solution {
public:
    int countElements(vector<int>& nums, int begin, int end, int x) {
        int n = 0;
        for (int i = begin; i < end; i++) {
            if (nums[i] == x) n++;
        }
        return n;
    }
    int getMaxTimesElement(vector<int>& nums, int begin, int end, int& times) {
        if (begin >= end) return nums[begin];
        if (begin + 1 == end) {
            times = 1;
            return nums[begin];
        }
        
        int timesLeft = 0;
        int halfLen = (end - begin) / 2;
        int mid = begin + halfLen;
        int maxLeft = getMaxTimesElement(nums, begin, mid, timesLeft);
        int timesRight = 0;
        int maxRight = getMaxTimesElement(nums, mid, end, timesRight);
        if (maxLeft == maxRight) {
            times = timesRight + timesLeft;
            return maxLeft;
        }
        else if (timesLeft < halfLen / 2) {
            times = timesRight;
            return maxRight;
        }
        else if (timesRight < halfLen / 2) {
            times = timesLeft;
            return maxLeft;
        }
        else {
            timesRight += countElements(nums, begin, mid, maxRight);
            timesLeft += countElements(nums, mid, end, maxLeft);
            if (timesRight > timesLeft)
                {
                    times = timesRight;
                    return maxRight;
                }
                else
                {
                    times = timesLeft;
                    return maxLeft;
                }
        }
    }
    int majorityElement(vector<int>& nums) {
        int times = 0;
        return getMaxTimesElement(nums, 0, nums.size(), times);
    }
};