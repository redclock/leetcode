//Write a function to find the longest common prefix string amongst an array of strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int prefixlen = 0;
        const string& head = strs[0];
        for (int i = 0; i < head.length(); i++) {
            char c = head[i];
            for (int j = 1; j < strs.size(); j++) {
                const string& s = strs[j];
                if (i >= s.length() || s[i] != c) goto result;
            }
            prefixlen++;
        }
    result:
        return head.substr(0, prefixlen);        
    }
};