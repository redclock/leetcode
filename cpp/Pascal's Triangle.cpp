/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r(numRows);
        if (numRows == 0) return r;
        r[0] = {1};
        if (numRows == 1) return r;
        for (int i = 1; i < numRows; i++) {
            vector<int>& line = r[i];
            vector<int>& lastRow = r[i - 1];
            line.resize(i + 1);
            line[0] = 1;
            for (int j = 0; j < i - 1; j++)
            {
                line[j + 1] = (lastRow[j] + lastRow[j+1]);
            }
            line[i] = 1;
        }
        return r;
    }
};