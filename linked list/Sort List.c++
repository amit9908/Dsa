class Solution {
public:
     ListNode* merge(ListNode* left , ListNode* right) {
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

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next  == NULL)return head;

        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);
        
        ListNode* mergeL = merge(left , right);
        return mergeL;
        
    }
};