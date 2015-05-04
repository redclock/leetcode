/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int k = rowIndex;
        long long x = 1;
        vector<int> r;
        r.push_back(1);
        for (int i = 1; i < k + 1; i ++)
        {
            x = x * (k-i+1) / i;
            r.push_back(x);
        }
        return r;
    }
};