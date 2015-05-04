/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/
class Solution {
public:
    string convertToTitle(int n) {
        string r = "";
        while (n > 0) {
            int d = n % 26;
            n /= 26;
            if (d == 0) {
                r += 'Z';
                n -= 1;
            }
            else {
                r += char('A' + d - 1);    
            }
        }
        for (int i = 0; i < r.size() / 2; i++) {
            char x = r[i];
            r[i] = r[r.size() - 1 - i];
            r[r.size() - 1 - i] = x;
        }
        return r;
    }
};