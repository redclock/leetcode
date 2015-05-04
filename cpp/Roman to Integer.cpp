/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int romanToInt(string s) {
        int r = 0;
        const char* str = s.c_str();
        int lastdig = 100000;
        int curnum = 0;
        while (*str) {
            int curdig;
            switch (*str) {
                case 'I': curdig = 1; break;
                case 'V': curdig = 5; break;
                case 'X': curdig = 10; break;
                case 'L': curdig = 50; break;
                case 'C': curdig = 100; break;
                case 'D': curdig = 500; break;
                case 'M': curdig = 1000; break;
                default: return 0;
            }
            if (curdig == lastdig)
                curnum += curdig;
            else if (curdig < lastdig) {
                r += curnum;
                curnum = curdig;
            }
            else {
                r += curdig - curnum;
                curnum = 0;
            }
            lastdig = curdig;
            str++;
        }
        return curnum + r;
    }
};