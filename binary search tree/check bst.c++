class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root,int min,int max) {
    if(!root)
    return true;

    if(root->data>min and root->data < max) {
        bool left = isBST(root->left,min,root->data);
        bool right = isBST(root->right,root->data,max);
        return left and right;
    }
    else
    return false;
    }
    bool isBST(Node* root) 
    {
        // Your code here
         return isBST(root,INT_MIN,INT_MAX);
    }
};