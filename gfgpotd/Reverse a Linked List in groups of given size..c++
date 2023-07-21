
class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head == NULL)return NULL;
        
        int count = 0;
        struct node* prev = NULL;
        struct node* curr = head;
        struct node* next = NULL;
        
        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(curr != NULL){
            head->next = reverse(next , k);
        }
        return prev;
    }
};