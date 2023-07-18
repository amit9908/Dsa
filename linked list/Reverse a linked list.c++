class Solution {
public:
    // Function to reverse a linked list.
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        
        while (curr != nullptr) {
            Node* next = curr->next;  // Store the next node.
            curr->next = prev;       // Reverse the link of the current node.
            prev = curr;             // Move prev and curr pointers one step forward.
            curr = next;
        }
        
        return prev;  // Return the new head of the reversed list.
    }
    
    Node* reverseList(Node* head) {
        return reverse(head);
    }
};
