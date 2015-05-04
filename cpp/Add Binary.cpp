/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        int maxlen = len1 > len2 ? len1 : len2;
        string result(maxlen, ' ');
        int index1 = len1 - 1;
        int index2 = len2 - 1;
        int more = 0;
        for (int i = maxlen - 1; i >= 0; i--) {
            int dig1 = index1 < 0 ? 0 : a[index1--] - '0';
            int dig2 = index2 < 0 ? 0 : b[index2--] - '0';
            more += dig1 + dig2;
            result[i] = (more & 1) + '0';
            more >>= 1;
        }
        return more ? string("1") + result : result;
    }
};