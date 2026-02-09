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
    void inorder(TreeNode*root, vector<int>&in){
        if(!root)return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    TreeNode* create(vector<int>&in, int l, int r){
        if(l>r)return NULL;
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(in[mid]);
        node->left = create(in, l, mid-1);
        node->right = create(in, mid+1, r);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root, in);
        return create(in, 0, in.size()-1);
    }
};