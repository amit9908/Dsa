class Solution {
public:
   int getLen(ListNode* head) {
       int len = 0;
       while (head != NULL) {
           len++;
           head = head->next; 
       }
       return len;
   }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head; // Added a check for empty list and k==0 cases

        int len = getLen(head);
        int actualRotate = k % len;

        if (actualRotate == 0) return head; // No rotation needed

        int newLastNodePos = len - actualRotate - 1;
        ListNode* newLastNode = head;
        
        for (int i = 0; i < newLastNodePos; i++) {
            newLastNode = newLastNode->next;
        }
        
        ListNode* newHead = newLastNode->next; // Corrected the variable name from newhead to newHead
        newLastNode->next = nullptr; // Set the next pointer of newLastNode to nullptr since it becomes the new tail

        ListNode* it = newHead;
        while (it->next) {
            it = it->next;
        }

        it->next = head;
        return newHead;
    }
};