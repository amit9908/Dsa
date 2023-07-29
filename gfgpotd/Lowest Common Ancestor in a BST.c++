class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            if(!root) return NULL;
            if(root->data == n1 || root->data == n2) return root;
            
            Node* leftAns = LCA(root->left , n1 , n2);
            Node* rightAns = LCA(root->right , n1 , n2);
            
            if(leftAns != NULL && rightAns != NULL) return root;
            else if(leftAns != NULL && rightAns == NULL) return leftAns;
            else if(leftAns == NULL && rightAns != NULL) return rightAns;
            else return NULL;
            
        }

};