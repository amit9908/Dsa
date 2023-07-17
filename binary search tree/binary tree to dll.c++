class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void solve(Node* root , Node*& head ){
        if(!root) return;
        
        solve(root->right , head);
        root->right = head;
        if(head != NULL){
            head->left = root;
        }
        head = root;
        
        solve(root->left , head);
        
        
    }
    Node * bToDLL(Node *root)
    {
        // your code here
        Node* head=NULL;
        solve(root,head);
        return head;
        
         
        
    }
};