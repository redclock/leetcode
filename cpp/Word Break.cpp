/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code"
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_set<char> wordChars;
        unordered_map<char, vector<string>> mapWords;
        for (auto itr = wordDict.begin(); itr != wordDict.end(); ++itr) {
            const string& word = *itr;
            if (!word.empty()) mapWords[word[word.length() - 1]].push_back(word);
            for (int i = 0; i < word.length(); i++) wordChars.insert(word[i]);
        }
        for (int i = 0; i < s.length(); i++) {
            if (wordChars.find(s[i]) == wordChars.end()) return false;
        }
        
        vector<bool> matchLen(s.length(), false);
        for (int i = 0; i < s.length(); i++) {
            auto itr = mapWords.find(s[i]);
            if (itr == mapWords.end()) continue;
            const vector<string>& words = itr->second;
            for (int iWord = 0; iWord < words.size(); iWord++) {
                const string& word = words[iWord];
                int wordLen = word.length();
                if (wordLen <= i && !matchLen[i - wordLen]) continue;
                int starti = i - wordLen + 1;
                if (starti < 0) continue;

                bool match = true;
                for (int j = 0; j < wordLen - 1; j++) {
                    if (s[starti + j] != word[j]) {
                        match = false;
                        break;
                    }
                }
                matchLen[i] = match;
                if (match) break;
            }
        }
        
        return matchLen[s.length() - 1];
    } 
};