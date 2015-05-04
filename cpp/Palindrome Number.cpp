// Determine whether an integer is a palindrome. Do this without extra space.

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int len = (int)(log(x) / log(10)) + 1;
        int highten = (int)(pow(10, len - 1));
        int lowten = 1;
        int y = x;
        int p = 0;
        for (int i = 0; i < len / 2; i++) {
            int d = y % 10;
            y /= 10;
            p += (highten + lowten) * d;
            highten /= 10;
            lowten *= 10;
        }
        if (len & 1) {
            p += highten * (y % 10);
        }
        return p == x;
        
    }
};