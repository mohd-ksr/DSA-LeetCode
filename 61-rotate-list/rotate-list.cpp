class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head; // koi node nhi ya ek node h to kitta bhi rotate kr lo same rahega

        ListNode* temp = head;
        stack<ListNode*>st; // starting se last tak satck me push krenge taki last wale stack me top pe rahe
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        int size = st.size(); // satck ka size matlb number of nodes
        k=k%size; // k ko size ke range me la lo
        
        while(k--){ // jab tk k 0 nhi ho jata
            ListNode* last = st.top(); // last element nikalo stack se
            st.pop();

            last->next=head; // satrting me connect kr do
            head=last; // head ko piche le jao matlb starting me 
        }
        st.top()->next = nullptr; // hamko pta hai stack top pe hamesha last element rahega to last element ka next null kr do

        return head; // or updated head return kr do
    }
};