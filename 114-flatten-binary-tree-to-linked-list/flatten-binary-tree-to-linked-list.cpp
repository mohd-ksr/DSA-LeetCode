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
// private:
//     void dfs(TreeNode*root,stack<TreeNode*>&st){
//         if(!root)return;
//         st.push(root);
//         dfs(root->left,st);
//         dfs(root->right,st);
//     }
//     TreeNode*LL(stack<TreeNode*>&st){
//         TreeNode*head=nullptr;
//         while(!st.empty()){
//             st.top()->left=nullptr;
//             st.top()->right=head;
//             head=st.top();
//             st.pop();
//         }
//         return head;
//     }
public:
    TreeNode*prev = nullptr;
    void flatten(TreeNode* root) {
        // stack<TreeNode*>st;
        // dfs(root,st);
        // root=LL(st);
        // if(!root)return;
        // flatten(root->right);
        // flatten(root->left);
        // root->right = prev;
        // root->left = nullptr;
        // prev = root;

        // by morris traversel
        TreeNode*curr = root;
        while(curr){
            if(curr->left){
                prev = curr->left;
                while(prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left; 
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
// Time Complexity O(n) 
// Space Complexity O(n) and for morris traversal O(1)