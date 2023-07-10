class Solution {
  public:
    int nodeCount( Node* root){
        if(!root) return 0;
        int left = nodeCount(root->left);
        int right = nodeCount(root->right);
        
        return left+right+1;
    }
    bool isCBT(struct Node* root , int i , int& n){
        if(!root) return true;
        if(i > n) return false;
        return isCBT(root->left , 2*i , n) && isCBT(root->right , 2*i+1 , n);
    }
    bool isMax(struct Node* root){
        if(!root) return true;
        int left = isMax(root->left);
        int right = isMax(root->right);
        int ans = false;
        if(!root->left && !root->right){
            ans = true;
        }else if(root->left && !root->right){
            ans = root->data  > root->left->data;
        }else{
            ans = root->data  > root->left->data && root->data  > root->right->data;
        }
        
        return ans;
        
    }
    bool isHeap(struct Node* tree) {
        // code here
        int n  = nodeCount(tree);
        int i = 1;
        return isCBT(tree , i , n) && isMax(tree);
    }
};