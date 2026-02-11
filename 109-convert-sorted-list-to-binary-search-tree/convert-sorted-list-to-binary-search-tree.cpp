/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* create(vector<int>&in, int l, int r){
        if(l>r)return NULL;
        int mid = l+(r-l)/2;
        TreeNode* node =new TreeNode(in[mid]);
        node->left = create(in, l, mid-1);
        node->right = create(in, mid+1, r);


        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>in;
        while(head){
            in.push_back(head->val);
            head=head->next;
        }

        return create(in, 0, in.size()-1);
    }
};