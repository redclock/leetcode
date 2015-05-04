/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        long long five = 5;
        int count = 0;
        while (n >= five) {
            count += n / five;
            five *= 5;

        }
        return count;
    }
};