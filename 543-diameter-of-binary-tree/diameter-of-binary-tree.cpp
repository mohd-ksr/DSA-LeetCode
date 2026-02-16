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
private:    
    int dfs(TreeNode* root, int &ans){
        if(!root)return 0;
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        ans = max(ans, 1+l+r);
        return 1+max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans-1;
    }
};