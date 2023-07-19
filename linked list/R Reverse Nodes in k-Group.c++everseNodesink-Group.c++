class Solution {
public:
    ListNode* reverseKGroup(ListNode* h, int k) {
        if(h==NULL || k==1)return h;
        ListNode*c=h;
        ListNode*p=NULL;
        ListNode*n=NULL;
        ListNode* cursor = h;

        // this loop is to check if no of nodes <k
        // if yes then don't reverse 
        // and return the head
        for(int i = 0; i < k; i++){
         if(cursor == NULL) 
            return h;
         cursor = cursor->next;
        }
        int cnt=0;
        while(c && cnt<k){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
            cnt++;
        }
        if(n)h->next=reverseKGroup(n,k);
        return p;
    }
};