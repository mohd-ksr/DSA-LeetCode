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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*head=nullptr;
        if(list1==nullptr && list2!=nullptr){
            return list2;
        }
        if(list2==nullptr && list1!=nullptr){
            return list1;
        }
        if(list2==nullptr && list1==nullptr){
            return nullptr;
        }

        if(list1->val<list2->val){
            head=list1;
            list1=list1->next;
        }
        else{ 
            head=list2;
            list2=list2->next;
        }
        ListNode*temp=head;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<list2->val){
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=temp->next;
                list2=list2->next;
            }
        }
        while(list1!=nullptr){
            temp->next=list1;
            temp=temp->next;
            list1=list1->next;
        }
        while(list2!=nullptr){
            temp->next=list2;
            temp=temp->next;
            list2=list2->next;
        }

        return head;

        
    }
};
// Time Complexity O(n + m)
// Space Complexity O(1)