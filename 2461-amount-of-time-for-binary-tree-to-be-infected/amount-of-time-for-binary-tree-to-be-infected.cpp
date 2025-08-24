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
    TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*, TreeNode*>&mapp, int start){
        queue<TreeNode*>q;
        TreeNode*res;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            if(node->val==start)res=node;
            q.pop();
            if(node->left){
                mapp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mapp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
    int findMaxDistance(map<TreeNode*, TreeNode*>&mapp, TreeNode*target){
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*,int>vis;
        vis[target]=1;
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            int fl=0;
            for(int i=0; i<sz; i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    fl=1;
                    vis[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    fl=1;
                    vis[node->right]=1;
                    q.push(node->right);
                }
                if(mapp[node] && !vis[mapp[node]]){
                    fl=1;
                    vis[mapp[node]]=1;
                    q.push(mapp[node]);
                }
            }
            if(fl)ans++;
        }
        return ans;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*>mapp;
        TreeNode*target=bfsToMapParents(root,mapp,start);
        int ans=findMaxDistance(mapp,target);
        return ans;
    }
};