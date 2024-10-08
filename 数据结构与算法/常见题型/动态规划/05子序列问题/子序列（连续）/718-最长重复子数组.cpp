class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n  = nums1.size(), m = nums2.size(), res = 0;
        // f[i][j]表示以nums1中第i个数，nums2中第j个数结尾的最长重复子数组
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(nums1[i - 1] == nums2[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                res = max(res, f[i][j]);
            }
        }

        return res;
    }
};