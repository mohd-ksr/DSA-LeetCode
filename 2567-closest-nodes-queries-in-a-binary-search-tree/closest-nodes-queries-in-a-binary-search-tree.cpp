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
        vector<int>inorder;
        int cciel(int n){
            int s = 0, e = inorder.size()-1;
            int ans = -1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(inorder[mid]==n)return n;
                if(inorder[mid]<n)s = mid+1;
                else{
                    e = mid-1;
                    ans = inorder[mid];
                }
            }
            return ans;
        }
        int ffloor(int n){
            int s = 0, e = inorder.size()-1;
            int ans = -1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(inorder[mid] == n)return n;
                if(inorder[mid] < n){
                    s = mid+1;
                    ans = inorder[mid];
                }
                else e = mid-1;
            }
            return ans;
        }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        // morris Inorder traversal
        TreeNode*curr = root;
        while(curr){
            if(!curr->left){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode*prev = curr->left;
                while(prev->right && prev->right!=curr)prev = prev->right;
                if(!prev->right){
                    prev->right = curr;
                    curr = curr -> left;
                }
                else{
                    prev->right = nullptr;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        
        vector<vector<int>>ans;
        for(auto &q:queries){
            ans.push_back({ffloor(q),cciel(q)});
        }
        return ans;
    }
};
// Time Complexity O(n + m*log(n)) where n is number of nodes in tree and m is size of queuries
// Space complexity O(n) for storing values of tree;