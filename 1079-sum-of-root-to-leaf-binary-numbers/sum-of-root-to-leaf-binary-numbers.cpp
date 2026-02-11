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
    void solve(TreeNode*root, int num, int &ans){
        if(!root)return;
        num<<=1;
        if(root->val==1){
            num+=1;
        }
        if(!root->left && !root->right){
            ans+=num;
            return;
        }
        solve(root->left, num, ans);
        solve(root->right, num, ans);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int num = 0;
        int ans = 0;
        solve(root, num, ans);
        return ans;
    }
};