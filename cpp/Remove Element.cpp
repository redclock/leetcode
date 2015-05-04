/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int* arr = &nums[0];
        int count = nums.size();
        int src = 0;
        int dst = 0;
        while (src < count) {
            if (arr[src] != val) {
                if (src != dst) arr[dst] = arr[src];
                dst++;
            }
            src++;
        }
        return dst;
    }
};