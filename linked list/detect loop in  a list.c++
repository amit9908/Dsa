class Solution
{
    private:
    
    //Function to detect the cycle in the list
    Node* cycle(Node* head)
    {
        if(head == NULL)
            return head;
            
        Node* slow = head;
        Node* fast = head;
        
        while(slow != NULL && fast != NULL)
        {
            fast = fast -> next;
            
            if(fast != NULL)
                fast = fast -> next;
                
            slow = slow -> next;
            
            if(slow == fast)
                return slow;
        }
        return NULL;
    }