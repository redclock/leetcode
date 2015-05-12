/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        struct recmd {
            char ch;
            bool star;
        };
        vector<recmd> cmds;
        for (int i = 0; i < p.length(); i++){
            recmd cmd;
            cmd.ch = p[i];
            if (i < p.length() - 1 && p[i+1] == '*') {
                i++;
                cmd.star = true;
            }
            else {
                cmd.star = false;
            }
            cmds.push_back(cmd);
        }
        bool* lastMatch = new bool[cmds.size() + 1];
        bool* curMatch = new bool[cmds.size() + 1];
        memset(curMatch, 0, sizeof(bool) * (cmds.size() + 1));
        curMatch[0] = true;
        int curLen = 0;
        for (int i = 0; i < cmds.size(); i++) {
            if (cmds[i].star) 
            {
                curMatch[i + 1] = true;
                curLen++;
            }
            else break;
        }
        int lastLen = 0;
        for (int i = 0; i < s.length(); i++) {
            bool* temp = lastMatch;
            lastMatch = curMatch;
            curMatch = temp;
            lastLen = curLen;
            memset(curMatch, 0, sizeof(bool) * (cmds.size() + 1));
            char ch = s[i];
            for (int j = 1; j <= cmds.size(); j++) {
                auto& cmd = cmds[j - 1];
                bool match = cmd.ch == '.' || cmd.ch == ch;
                if (cmd.star) {
                    curMatch[j] = curMatch[j - 1];
                    if (match) {
                        curMatch[j] = curMatch[j] || lastMatch[j];
                    }
                }
                else if (match &&lastMatch[j - 1]) {
                    curMatch[j] = true;
                }
            }
        }
        return curMatch[cmds.size()];
    }
};