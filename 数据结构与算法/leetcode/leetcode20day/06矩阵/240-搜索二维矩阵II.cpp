class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 抽象为二叉树
        int i = matrix.size() - 1, j = 0;
        while(i >= 0 && j < matrix[0].size()) {
            if(matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j] > target) {
                --i;
            } else {
                ++j;
            }
        }

        return false;
    }
};