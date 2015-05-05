/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int charMap[256];
        for (int i = 0; i < 256; i++) charMap[i] = -1;
        int maxLen = 0;
        int start = 0;
        int strlen = s.length();
        for (int i = 0; i < strlen; i++) {
            char ch = s[i];
            int index = charMap[ch];
            if (index >= start) {
                int len = i - start;
                if (len > maxLen) maxLen = len;
                start = index + 1;
            }
            charMap[ch] = i;
        }
        int len = s.length() - start;
        if (len > maxLen) maxLen = len;
        return maxLen;
    }
};