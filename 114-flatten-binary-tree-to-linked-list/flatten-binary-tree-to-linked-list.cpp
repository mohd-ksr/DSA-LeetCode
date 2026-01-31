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
    void preOrder(TreeNode*root, stack<TreeNode*>&st){
        while(!root)return;
        st.push(root);
        preOrder(root->left, st);
        preOrder(root->right, st);
    }
    TreeNode* createLL(stack<TreeNode*>&st){
        TreeNode * head=nullptr;
        while(!st.empty()){
            TreeNode* node = st.top(); st.pop();
            node->left = nullptr;
            node->right = head;
            head=node;
        }
        return head;

    }
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*>st;
        preOrder(root, st);
        root= createLL(st);
    }
};