/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;
        unordered_map<char, vector<int>> charPosMap;    
        for (int i = 0; i < s.length(); i++) 
            charPosMap[s[i]].push_back(i);
        int maxLen = 1;
        int maxStart = 0;
        vector<int> pres1;
        vector<int> pres2;
        vector<int> *lastPres = &pres1;
        lastPres->push_back(0);
        vector<int> *pres = &pres2;
        for (int i = 1; i < s.length(); i++) {
            pres->push_back(i);
            if (s[i - 1] == s[i]) {
                pres->push_back(i - 1);
                if (maxLen < 2) {
                    maxLen = 2;
                    maxStart = i - 1;
                }
            }
            for (int lastpre: *lastPres) {
                int prePos = lastpre - 1;
                if (prePos >= 0 && s[prePos] == s[i]) {
                    pres->push_back(prePos);
                    int len = i - prePos + 1;
                    if (len > maxLen) { maxLen = len; maxStart = prePos; }
                }
            }
            vector<int>* temp = pres;
            pres = lastPres;
            pres->clear();
            lastPres = temp;
        }
        return s.substr(maxStart, maxLen);
    }
};