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
        if(head==NULL || head->next==NULL)return head;
        stack<ListNode*>st;
        ListNode*ptr = head;
        while(ptr!=NULL){
            st.push(ptr);
            ptr=ptr->next;
        }
        int size = st.size();
        k = k%size;

        for(int i=0; i<k; i++){
            ListNode * last = st.top();
            st.pop();
            last->next = head;
            head = last;
            st.top()->next = NULL;
        }
        return head;
    }
};