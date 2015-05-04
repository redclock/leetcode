/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        const char* begin = s.c_str();
        const char* end = begin;
        int len = 0;
        while (*begin) {
            while (*begin == ' ') *begin++;
            end = begin;
            while (*end && *end != ' ') *end++;
            int wordlen = end - begin;
            if (wordlen > 0) len = wordlen;
            begin = end;
        }
        return len;
    }
};