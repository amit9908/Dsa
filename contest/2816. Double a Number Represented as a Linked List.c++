class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL, *nex = NULL;
        while(curr != NULL)
        {
            nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }
        //ListNode *nHead = prev;
        curr = prev;
        int carry = 0;
        while(curr)
        {
            int v = curr -> val * 2 + carry;
            curr -> val = v % 10;
            carry = v / 10;
            nex = curr;
            curr = curr -> next;
        }
        if(carry == 1)
            nex -> next = new ListNode(1);
        curr = prev;
        prev = NULL, nex =NULL;
        while(curr != NULL)
        {
            nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
}