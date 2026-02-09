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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        deque<ListNode*>dq;
        while(head){
            dq.push_back(head);
            head=head->next;
        }
        bool tog = true;
        head = new ListNode();
        ListNode * temp = head;
        while(!dq.empty()){
            if(tog){
                temp->next = dq.front();
                dq.pop_front();
            }
            else{
                temp->next = dq.back();
                dq.pop_back();
            }
            temp=temp->next;
            tog=!tog;
        }
        temp->next=nullptr;
        head=head->next;
    }
};