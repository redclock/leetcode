//Implement atoi to convert a string to an integer.

class Solution {
public:
    int myAtoi(string str) {
        const char* s = str.c_str();
        while (*s && *s <= 32) s++;
        bool neg = false;
        if (*s == '+') s++;
        else if (*s == '-') {neg = true; s++;}
        long long r = 0;
        while (*s >= '0' && *s <= '9'){
            r = r * 10 + *s - '0';
            if (r > INT_MAX)
                return neg ? INT_MIN : INT_MAX;
            s++;
        }
        return neg ? -r : r;
    }
};