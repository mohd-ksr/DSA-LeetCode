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
    int countSwap(vector<int>&nums){
        int n = nums.size();
        vector<pair<int, int>>v(n);
        for(int i=0; i<n; i++)v[i]={nums[i], i};
        sort(v.begin(), v.end());
        vector<bool>vis(n, false);
        int ans=0;
        for(int i=0; i<n; i++){
            if(vis[i] || v[i].second==i)continue;
            int c=0;
            int j=i;
            while(!vis[j]){
                vis[j]=true;
                j=v[j].second;
                c++;
            }
            if(c>1)ans+=c-1;
        }

        return ans;
    }
public:
    int minimumOperations(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int size = q.size();
            vector<int>l;
            for(int i=0; i<size; i++){
                TreeNode*node = q.front(); q.pop();
                l.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(l.size()>1)ans+=countSwap(l);
        }
        return ans;
    }
};