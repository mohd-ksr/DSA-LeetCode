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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s(nums.begin(), nums.end());
        ListNode* curr = head;
        while(curr->next){
            if(s.find(curr->next->val)!=s.end()){
                curr->next=curr->next->next;
            }
            else curr = curr->next;
        }
        if(s.find(head->val)!=s.end())head=head->next;
        return head;
    }
};
// Time Complexity O(n)