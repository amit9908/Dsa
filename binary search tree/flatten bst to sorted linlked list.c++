void in(Node* root , Node*& prev){
    if(!root) return;
    in(root-left , prev);
    prev->left = 0;
    prev->right = root;
    prev = root;
    in(root->right , prev);
}

Node* flatten(Node* root){
    Node* dummy = new Node*(-1);
    Node* prev = dummy;
    in(root , prev);
    prev->left = prev->right = 0;
    return dummy->right;
}