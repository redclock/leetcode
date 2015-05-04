/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length())
            return -1;
        if (needle.length() == 0) return 0;
        int len = haystack.length() - needle.length();
        for (int i = 0; i <= len; i++) {
            if (haystack[i] == needle[0]) {
                bool found = true;
                for (int j = 1; j < needle.length(); j++) {
                    if (needle[j] != haystack[i + j]) {
                        found = false;
                        break;
                    }
                }
                if (found) return i;
            }
        }
        return -1;
    }
};