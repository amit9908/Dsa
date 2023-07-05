/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void tleft(Node *root ,vector<int> &ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL)) return ;
        ans.push_back(root->data);
        
       if(root->left){
           tleft(root->left , ans);
       }else tleft(root->right , ans);
    }
    
    void boundary(Node *root , vector<int> &ans){
        if(root == NULL) return ;
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        boundary(root->left , ans);
        boundary(root->right , ans);
    }
    void tright(Node *root , vector<int> &ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL)) return ;
        
        if(root->right){
            tright(root->right , ans);
        }else tright(root->left , ans);
        
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL) return ans;
        
        ans.push_back(root->data);
        
        tleft(root->left  , ans);
        
        boundary(root->left , ans);
        boundary(root->right ,ans);
        
        tright(root->right , ans);
        
        return ans;
        
    }
};