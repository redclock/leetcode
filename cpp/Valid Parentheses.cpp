/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '(': stack.push_back(')'); break;
                case '[': stack.push_back(']'); break;
                case '{': stack.push_back('}'); break;
                default: 
                    if (stack.empty()) return false;
                    if (stack.back() != s[i]) return false;
                    stack.pop_back();
            }
        }
        return stack.empty();
    }
};