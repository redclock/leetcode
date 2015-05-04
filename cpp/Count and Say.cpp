/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
class Solution {
public:
    string read(const string& org) {
        const char* s = org.c_str();
        int count = 1;
        char ch = *s;
        string result;
        do {
            s++;
            if (*s != ch){
                result += to_string(count);
                result += ch;
                ch = *s;
                count = 1;
            }
            else {
                count ++;
            }
        } while (*s);
        return result;
    }
    
    string countAndSay(int n) {
        if (n <= 0) return "";  
        string s = "1";
        for (int i = 1; i < n; i++) {
            s = read(s);
        }
        return s;
        
    }
};