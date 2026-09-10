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
    // [ans, nodes_count, Sum]
    vector<int>solve(TreeNode* root){
        if(!root){
            return {0,0,0};
        }
        auto l = solve(root->left);
        auto r = solve(root->right);
        int ans = l[0]+r[0];
        int nc = l[1]+r[1];
        int sum = l[2]+r[2];
        sum+=root->val;
        nc++;
        ans+=((sum/nc) == root->val);
        return {ans, nc, sum};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        return solve(root)[0];
    }
};