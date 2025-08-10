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
    int solve(TreeNode*root){
        if(!root)return 0;
        int l=solve(root->left);
        if(l==-1)return -1;
        int r=solve(root->right);
        if(r==-1)return -1;
        if(abs(l-r)>1)return -1;
        return 1+max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        // BruteForce-- Time complexity O(n^2)
        // int l=height(root->left);
        // int r=height(root->right);
        // if(abs(l-r)>1)return false;
        // bool le=isBalanced(root->left);
        // bool ri=isBalanced(root->right);
        // if(!le || !ri)return false;
        // return true;
        
        // Logic of finding hieght of BT-- Time complexity O(n)
        return solve(root)!=-1;
    }
};