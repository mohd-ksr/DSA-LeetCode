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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        while(head){
            st.push(head);
            head=head->next;
        }

        int maxi = st.top()->val;
        head = st.top(); st.pop();
        while(!st.empty()){
            ListNode* node = st.top();
            if(node->val>=maxi){
                node->next=head;
                head=node;
                maxi=node->val;
            }
            st.pop();
        }
        return head;
    }
};