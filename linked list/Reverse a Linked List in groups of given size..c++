class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head == NULL){
            return NULL;
        }
        
        struct node* prev = NULL;
        struct node* next = NULL;
        struct node* curr = head;
        
        int count =0;
        
        while(curr != NULL && count <k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count ++;
        }
        
        if(next != NULL){
             head->next = reverse(next, k);
        }
        
        return prev;
    }
};