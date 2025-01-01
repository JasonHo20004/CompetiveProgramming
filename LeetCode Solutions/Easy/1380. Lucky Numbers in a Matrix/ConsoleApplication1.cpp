class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> minInRows(m, INT_MAX);
        unordered_map<int, int> rowtoColMap;
        for (int i = 0; i < m; ++i) {
            int minRowVal = INT_MAX;
            int minColIndex = -1;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < minRowVal) {
                    minRowVal = matrix[i][j];
                    minColIndex = j;
                }
            }
            minInRows[i] = minRowVal;
            rowtoColMap[i] = minColIndex;
        }
        vector<int> luckyNumbers;
        for (int i = 0; i < m; ++i) {
            int minRowVal = minInRows[i];
            int colIndex = rowtoColMap[i];
            bool isLucky = true;
            for (int j = 0; j < m; ++j) {
                if (matrix[j][colIndex] > minRowVal) {
                    isLucky = false;
                    break;
                }
            }
            if (isLucky) {
                luckyNumbers.push_back(minRowVal);
            }
        }
        return luckyNumbers;
    }
};