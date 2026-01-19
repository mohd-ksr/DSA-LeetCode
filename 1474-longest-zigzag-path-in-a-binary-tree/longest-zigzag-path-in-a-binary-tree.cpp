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
    void dfs(TreeNode* root, bool goLeft, int steps, int &ans){
        if(!root)return;
        ans = max(ans, steps);
        if(goLeft){
            dfs(root->left, false, steps+1, ans);
            dfs(root->right, true, 1, ans);
        }
        else{
            dfs(root->left, false, 1, ans);
            dfs(root->right, true, steps+1, ans);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, true, 0, ans);
        return ans;
    }
};