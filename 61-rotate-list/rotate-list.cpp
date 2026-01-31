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
    ListNode* rotateRight(ListNode* head, int k) {
        deque<ListNode*>dq;
        ListNode* temp = head;
        while(head){
            dq.push_back(head); 
            head=head->next;
        }
        if(dq.size()==0 || k==0)return temp;
        k=k%dq.size();
        while(k--){
            ListNode * node = dq.back();
            dq.pop_back();
            dq.push_front(node);
        }
        head=nullptr;
        while(!dq.empty()){
            ListNode * node = dq.back();
            node->next=head;
            head=node;
            dq.pop_back();
        }
        return head;
    }
};