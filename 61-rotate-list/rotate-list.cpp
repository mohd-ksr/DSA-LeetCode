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
        ListNode* ptr = head;
        int size = 1;
        while(ptr->next){
            size++;
            ptr=ptr->next;
        }
        ptr->next = head;
        k = k%size;
        k = size-k;
        k--;
        ptr = head;
        while(k--){
            ptr=ptr->next;
        }
        head = ptr->next;
        ptr->next = nullptr;
        return head;
    }
};