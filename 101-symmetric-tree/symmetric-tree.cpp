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
    bool check(TreeNode*left, TreeNode* right){
        if(!left || !right)return left==right;
        if(left->val!=right->val)return false;
        return check(left->left,right->right) && check(left->right,right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return !root || check(root->left,root->right);
    }
};
// Time Complexity O(N)