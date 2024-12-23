class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[1][1] = 1;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == 1 && j == 1) continue;
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }

        return f[m][n];
    }
};