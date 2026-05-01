class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;
        
        ListNode* temp = head;
        stack<ListNode*>st;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        int size = st.size();
        k=k%size;
        
        while(k--){
            ListNode* last = st.top();
            st.pop();

            last->next=head;
            head=last;
        }
        st.top()->next = nullptr;

        return head;
    }
};