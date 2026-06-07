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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int>st;
        for(auto v:descriptions){
            st.insert(v[1]);
        }
        int r;
        for(auto v:descriptions){
            if(!st.count(v[0])){
                r=v[0];
                break;
            }
        }
        TreeNode* root = new TreeNode(r);
        unordered_map<int, TreeNode*>mapp;
        mapp[r]=root;

        for(auto v:descriptions){
            int p = v[0];
            int c = v[1];
            int isLeft = v[2];

            if(mapp.find(p)!=mapp.end()){
                if(mapp.find(c)==mapp.end()){
                    TreeNode* child = new TreeNode(c);
                    mapp[c]=child; 
                }

                if(isLeft==1){
                        mapp[p]->left = mapp[c];
                }
                else{
                    mapp[p]->right = mapp[c];
                }
            }
            else{
                TreeNode* parent = new TreeNode(p);
                mapp[p]=parent;
                if(mapp.find(c)==mapp.end()){
                    TreeNode* child = new TreeNode(c);
                    mapp[c]=child; 
                }

                if(isLeft==1){
                        mapp[p]->left = mapp[c];
                }
                else{
                    mapp[p]->right = mapp[c];
                }
            }
        }
        return root;
    }
};