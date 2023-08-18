class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        
        ListNode* temp1 = small;
        ListNode* temp2 = large;

        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                ListNode* tempNext = temp->next;
                temp1->next = temp;
                temp1 = temp1->next;
                temp = tempNext;
            }else{
                ListNode* tempNext = temp->next;
                temp2->next = temp;
                temp2 = temp2->next; 
                temp = tempNext; 
            }

        }

        large = large->next;
        temp1->next = large;
        temp2->next = NULL;

        return small->next;
        
    }
};