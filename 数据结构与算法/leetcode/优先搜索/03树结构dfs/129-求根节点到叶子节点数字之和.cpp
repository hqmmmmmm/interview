/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    int sumNumbers(TreeNode* root) {
        dfs(root, "");  
        return ans;
    }

    void dfs(TreeNode *root, string path) {
        if(root == nullptr) return;
        
        path += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            ans += stoi(path);
            return;
        }

        dfs(root->left, path);
        dfs(root->right, path);
    }
};