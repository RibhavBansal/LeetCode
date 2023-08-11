class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), r = n-1, c = 0;
        while (r >= 0 && c < m) {
            if (matrix[r][c] == target) {
                return true;
            }
            matrix[r][c] > target ? r-- : c++;
        }
        return false;
    }
};