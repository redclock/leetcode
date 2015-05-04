/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool isAll9 = true;
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] != 9) {
                isAll9 = false;
                break;
            }
        }
        if (isAll9) {
            vector<int> result(digits.size() + 1, 0);
            result[0] = 1;
            return result;
        }
        int more = 1;
        vector<int> result = digits;
        for (int i = (int)result.size() - 1; i >= 0 && more; i--) {
            more += result[i];
            result[i] = more % 10;
            more /= 10;
        }
        return result;
    }
};