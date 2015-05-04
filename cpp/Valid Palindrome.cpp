/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        const char* start = s.c_str();
        const char* end = start + s.length() - 1;
        while (start < end) {
            while (start < end && !isalpha(*start) && !isdigit(*start)) start++;
            while (start < end && !isalpha(*end) && !isdigit(*end)) end--;
            if (tolower(*start) != tolower(*end)) return false;
            start++;
            end--;
        }
        return true;
    }
};