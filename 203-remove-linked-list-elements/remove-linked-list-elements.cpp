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
    ListNode* removeElements(ListNode* head, int key) {
        stack<ListNode*>st;
        while(head){
            st.push(head);
            head=head->next;
        }
        ListNode*prev=nullptr;
        while(!st.empty()){
            ListNode*node=st.top();
            if(node->val!=key){
                node->next=prev;
                prev=node;
            }
            st.pop();
        }
        return prev;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)

