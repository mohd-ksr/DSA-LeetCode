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
    void solve(TreeNode* root,int level,vector<int>&ans){
        if(!root)return;
        level++;
        if(level>ans.size()){
            ans.push_back(root->val);
        }
        solve(root->right,level,ans);
        solve(root->left,level,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // BFS
        // vector<int>ans;
        // if(!root)return ans;
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int n=q.size();
        //     for(int i=0; i<n; i++){
        //         TreeNode*node=q.front();
        //         q.pop();
        //         if(i==n-1)ans.push_back(node->val);
        //         if(node->left)q.push(node->left);
        //         if(node->right)q.push(node->right);
        //     }
        // }
        // return ans;

        // DFS
        vector<int>ans;
        solve(root,0,ans);
        return ans;
    }
};
// Time Complexity O(n)
// Space complexity O(h)






