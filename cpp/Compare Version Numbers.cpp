/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
class Solution {
public:
    int getNum(string& v, int& index) {
        char c;
        int num = 0;
        while (index < v.length() && (c = v[index++]) && c <= '9' && c >= '0') {
            num = num * 10 + c - '0';
        }
        return num;
    }
    int compareVersion(string version1, string version2) {
        int index1 = 0;
        int index2 = 0;
        while (index1 < version1.length() || index2 < version2.length()) {
            int num1 = getNum(version1, index1);
            int num2 = getNum(version2, index2);
            if (num1 > num2) return 1;
            if (num2 > num1) return -1;
        }
        return 0;
    }
};