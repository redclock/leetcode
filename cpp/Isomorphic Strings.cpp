/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

class Solution {
public:
    
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapChar;
        unordered_map<char, char> mapCharInv;
        if (s.length() != t.length()) return false;
        const char* sstr = s.c_str();
        const char* tstr = t.c_str();
        while (char sch = *sstr++) {
            char tch = *tstr++;
            auto itr = mapChar.find(sch);
            if (itr == mapChar.end()) {
                mapChar[sch] = tch;
                auto invitr = mapCharInv.find(tch);
                if (invitr != mapCharInv.end()) return false;
                mapCharInv[tch] = sch;
            }
            else {
                if (itr->second != tch) return false;
            }
        }
        return true;
    }
};