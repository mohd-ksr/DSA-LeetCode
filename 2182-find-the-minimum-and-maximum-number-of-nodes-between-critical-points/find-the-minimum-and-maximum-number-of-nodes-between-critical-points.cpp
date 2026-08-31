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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prevCrit = -1;
        int leftMost = -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int ind=0;
        int prev = head->val;
        head = head->next;
        ind++;
        if(!head)return {-1, -1};
        int curr = head->val;
        head = head->next;
        ind++;
        while(head){
            int next = head->val;
            if((curr>prev && curr>next) || (curr<prev && curr<next)){
                if(prevCrit!=-1){
                    mini = min(mini, ind-prevCrit);
                    maxi = max(maxi, ind-leftMost);
                }
                prevCrit=ind;
                if(leftMost==-1)leftMost=ind;
            }
            prev=curr;
            curr=next;
            ind++;
            head=head->next;
        }
        if(mini==INT_MAX)return {-1, -1};
        return {mini, maxi};
    }
};