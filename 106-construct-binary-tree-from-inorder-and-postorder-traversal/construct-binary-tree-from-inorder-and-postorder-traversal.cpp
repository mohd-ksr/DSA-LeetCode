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
    unordered_map<int, int> inorderIndex;
    int postIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        postIndex = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd){
        if (inStart > inEnd) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inorderIndex[rootVal];
        root->right = build(inorder, postorder, idx + 1, inEnd);
        root->left = build(inorder, postorder, inStart, idx - 1);
        return root;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)