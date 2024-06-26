class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        // 第一行和第一列是否需要置0
        bool row = false, col = false;
        if(matrix[0][0] == 0) row = col = true;
        else {
            for(int i = 0; i < n; ++i) {
                if(matrix[i][0] == 0) col = true;
            }
            for(int j = 0; j < m; ++j) {
                if(matrix[0][j] == 0) row = true;
            }
        }

        // 这里i和j要从1开始循环
        // 记录矩阵哪些行列需要置0
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // 矩阵置0
        for(int i = 1; i < n; ++i) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < m; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < m; ++j) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < n; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(row) for(int j = 0; j < m; ++j) matrix[0][j] = 0;
        if(col) for(int i = 0; i < n; ++i) matrix[i][0] = 0;
    }
};