/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return n;
        int pre2 = 1;
        int pre1 = 1;
        for (int i = 2; i <= n; i++) {
            int pre = pre1;
            pre1 = pre1 + pre2;
            pre2 = pre;
        }
        return pre1;
    }
};