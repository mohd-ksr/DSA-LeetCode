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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)return root;
        queue<TreeNode*>q;
        q.push(root);
        bool tog = false;
        while(!q.empty()){
            int size = q.size();
            vector<int>vals;
            vector<TreeNode*>nodes;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                vals.push_back(node->val);
                nodes.push_back(node);

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(tog){
                reverse(vals.begin(), vals.end());
                for(int i=0; i<vals.size(); i++){
                    nodes[i]->val = vals[i];
                }
            }
            tog=!tog;
        }
        return root;
    }
};