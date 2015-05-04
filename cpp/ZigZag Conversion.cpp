/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        int segLen = 2;
        for (int i = 0; i < numRows - 2; i++) segLen += 2;
        string r = "";
        size_t maxLen = s.length();
        int segs = (maxLen + segLen - 1) / segLen;
        for (int i = 0; i < segs; i++) {
            r += s[i * segLen]; 
        }
        int start = 0;
        int end = segLen;
        for (int line = 1; line < numRows - 1; line++) {
            start++;
            end--;
            for (int i = 0; i < segs; i++) {
                int sindex = i * segLen + start;
                int eindex = i * segLen + end;
                if (sindex < maxLen) r += s[sindex];
                if (eindex < maxLen) r += s[eindex];
            }
        }
        start++;
        for (int i = 0; i < segs; i++) {
            int index = i * segLen + start;
            if (index < maxLen) r += s[index]; 
        }
        return r;
    }
};