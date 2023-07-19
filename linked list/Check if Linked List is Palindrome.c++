class Solution{
public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // prev will be the new head of the reversed linked list.
    }
    
    bool isPalindrome(Node *head)
    {
        if(head == NULL)
            return true;
            
        if(head->next == NULL)
            return true;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        Node* reverLLHead = reverse(slow); // Reverse the second half of the linked list.
        
        Node* head1 = head;
        Node* head2 = reverLLHead;
        
        while(head1 != NULL && head2 != NULL){
            if(head1->data != head2->data){
                return false;
            }else{
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return true;
    }
};