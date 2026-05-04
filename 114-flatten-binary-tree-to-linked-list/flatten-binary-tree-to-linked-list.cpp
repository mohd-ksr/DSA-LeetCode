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
    vector<TreeNode*> ans;
public:

    void preorder(TreeNode* root){
        if(root == NULL)return ;
        ans.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        preorder(root);
        for(int i = 0; i<ans.size()-1; i++){
            ans[i]->left = NULL;
            ans[i]->right = ans[i+1];
        }
        ans[ans.size()-1]-> left = NULL;
        ans[ans.size()-1]-> right = NULL;
        
        
        
    }
};