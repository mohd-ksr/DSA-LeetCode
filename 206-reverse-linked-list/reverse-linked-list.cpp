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
private:
    ListNode* rev(ListNode* prev, ListNode*forw){
        if(!forw)return prev;
        ListNode*temp = forw;
        forw = forw->next;
        temp->next = prev;
        prev = temp;
        return rev(prev, forw);
    }
public:
    ListNode* reverseList(ListNode* head) {
        return rev(nullptr, head);
    }
};