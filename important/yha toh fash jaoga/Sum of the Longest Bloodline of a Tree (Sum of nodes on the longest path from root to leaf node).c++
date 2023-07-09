class Solution
{
public:
    pair<int,int> height(Node *root){
        if(!root) return {0,0};
        
        auto lh = height(root->left);
        auto rh = height(root->right);
        
        int sum = root->data;
        if(lh.first == rh.first){
            sum += lh.second>rh.second ? lh.second : rh.second;
        }
        else if(lh.first>rh.first){
            sum += lh.second;
        }else{
            sum += rh.second;
        } 
        
        return {1+max(lh.first ,rh.first) ,sum};
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        auto ans = height(root);
        return ans.second;
    }
};