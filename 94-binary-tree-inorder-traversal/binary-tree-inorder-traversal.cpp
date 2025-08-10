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
    void answer(TreeNode* root,vector<int>&ans){
        if(!root)return;
        answer(root->left,ans);
        ans.push_back(root->val);
        answer(root->right,ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // recursive--
        // vector<int>ans;
        // answer(root,ans);
        // return ans;

        // Iterative--
        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*>st;
        TreeNode*curr=root;
        while(curr||!st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
        return ans;
    }
};

// Time Complexity O(n)
// Space Complexity O(n)