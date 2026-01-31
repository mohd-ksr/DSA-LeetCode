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
    unordered_map<int, int>inMap;
    int pInd;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int is, int ie){
        if(is>ie)return NULL;

        int rootVal = postorder[pInd--];

        TreeNode * root = new TreeNode(rootVal);

        int ind = inMap[rootVal];

        root->right = build(inorder, postorder, ind+1, ie);
        root->left =  build(inorder, postorder, is, ind-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inMap[inorder[i]]=i;
        }
        pInd = n-1;

        return build(inorder, postorder, 0, n-1);
    }
};