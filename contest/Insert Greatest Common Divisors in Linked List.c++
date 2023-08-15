class Solution {
public:
    int gcd(int a , int b){
        if(a==0)return b;
        if(b==0)return a;
        
        while(a!=0 || b!=0){
            if(a == 0)return b;
            if(b == 0)return a;
            if(a>b){
                a = a-b;
            }else{
                b = b-a;
            }
        }
        return 0;
    }
    
    ListNode* solve(ListNode* head){
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            ListNode* s = temp->next;
            int gNod = gcd(temp->val , s->val);
            ListNode* t = new ListNode(gNod);
            temp->next = t;
            t->next = s;
            temp = temp->next->next;
        }
        return head;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head){
        return solve(head);
    }
};