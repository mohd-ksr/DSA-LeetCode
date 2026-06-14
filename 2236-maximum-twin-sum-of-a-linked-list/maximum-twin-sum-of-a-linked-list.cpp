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
public:
    int pairSum(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        int n = st.size();
        int ans = 0;
        for(int i=0; i<=n/2; i++){
            ans=max(ans, (head->val+st.top()->val));
            head=head->next;
            st.pop();
        }
        return ans;
    }
};