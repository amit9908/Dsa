class Solution {
public:
    ListNode* mergeTwoLists(ListNode* left , ListNode* right) {
        if(left == NULL)return right;
        if(right == NULL)return left;

        ListNode* ans = new ListNode(-1);
        ListNode* nptr = ans;

        while(left && right){
            if(left->val <= right->val){
                nptr->next = left;
                nptr = left;
                left = left->next; 
            }else{
                nptr->next = right;
                nptr = right;
                right = right->next; 
            } 
        }
        while(left){
            nptr->next = left;
            nptr = left;
            left = left->next; 
        }

        while(right){
            nptr->next = right;
            nptr = right;
            right = right->next; 
        }

        return ans->next;
    }
};