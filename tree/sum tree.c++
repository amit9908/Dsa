class Solution
{
    public:
    public:
    bool isSumTree(Node* root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return true;

        int leftSum = sumSubtree(root->left);
        int rightSum = sumSubtree(root->right);

        if (root->data == leftSum + rightSum && isSumTree(root->left) && isSumTree(root->right))
            return true;

        return false;
    }

    int sumSubtree(Node* node)
    {
        if (node == NULL)
            return 0;

        return node->data + sumSubtree(node->left) + sumSubtree(node->right);
    }

    
};