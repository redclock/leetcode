/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        bool neg = (x < 0);
        if (neg) x = -x;
        unsigned long long r = 0;
        while (x > 0) {
            int d = x % 10;
            x /= 10;
            r = r * 10 + d;
            if (r >= (1u << 31)) return 0;
        }
        return neg? -r : r;
    }
};