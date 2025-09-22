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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*>st;
        ListNode*temp=head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        n=n-1;
        ListNode* prev = nullptr;
        while(n--){
            if(!st.empty()){
                ListNode* node = st.top();
                node->next=prev;
                prev=node;
                st.pop();
            }
        }
        if(!st.empty())st.pop();
        while(!st.empty()){
            ListNode* node = st.top();
            node->next=prev;
            prev=node;
            st.pop();
        }
        return prev;
    }
};


