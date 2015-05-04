/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0;   
        int x2 = 0; 
        int mask = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            x2 ^= x1 & nums[i];
            x1 ^= nums[i];
            mask = ~(x1 & x2);
            x1 &= mask;
            x2 &= mask;
        }
        return x1;
    }
};