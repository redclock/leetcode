/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
    string intToRoman(int num) {
        char rom[100];
        char* s = rom + 99;
        *s-- = 0;
        const char* ones = "IXCM";
        const char* fives = "VLD";
        while (num > 0) {
            int d = num % 10;
            num /= 10;
            switch (d) {
                case 0: break;
                case 1: *s-- = *ones; break;
                case 2: *s-- = *ones; *s-- = *ones; break;
                case 3: *s-- = *ones; *s-- = *ones; *s-- = *ones; break;
                case 4: *s-- = *fives; *s-- = *ones; break;
                case 5: *s-- = *fives; break;
                case 6: *s-- = *ones; *s-- = *fives; break;
                case 7: *s-- = *ones; *s-- = *ones; *s-- = *fives; break;
                case 8: *s-- = *ones; *s-- = *ones; *s-- = *ones; *s-- = *fives; break;
                case 9: *s-- = *(ones + 1); *s-- = *ones; break;
            }
            ones++;
            fives++;
        }
        return s + 1;
    }
};