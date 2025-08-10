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
    void answer(TreeNode* root, vector<int>&ans){
        if(!root)return;
        answer(root->left,ans);
        answer(root->right,ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // recursive---
        // vector<int>ans;
        // answer(root,ans);
        // return ans;

        // iterative using 2 stacks---
        // vector<int>ans;
        // if(!root)return ans;
        // stack<TreeNode*>st1,st2;
        // st1.push(root);
        // while(!st1.empty()){
        //     TreeNode*node=st1.top();
        //     st2.push(node);
        //     st1.pop();
        //     if(node->left)st1.push(node->left);
        //     if(node->right)st1.push(node->right);
        // }
        // while(!st2.empty()){
        //     ans.push_back(st2.top()->val);
        //     st2.pop();
        // }
        // return ans;
        
        // iterative using 1 stacks---
        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*>st;
        TreeNode*lastVisited=nullptr;
        TreeNode*curr=root;
        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode*peekNode=st.top();
                if(peekNode->right && peekNode->right!=lastVisited){
                    curr=peekNode->right;
                }
                else{
                    ans.push_back(peekNode->val);
                    lastVisited=peekNode;
                    st.pop();
                }
            }
        }
        return ans;
    }
};

// Time complexity O(n)
// Space complexity O(n)








