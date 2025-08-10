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
    int solve(TreeNode* root, int &maxi){
        if(!root)return 0;
        int l=solve(root->left,maxi);
        int r=solve(root->right,maxi);
        maxi=max(maxi,l+r);
        return 1+max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       int maxi=0;
       solve(root,maxi);
       return maxi;
    }
};
// Time complexity O(n);
// Space complexity O(1);