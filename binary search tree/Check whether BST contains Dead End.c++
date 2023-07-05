void fun(Node *root , unordered_map<int , bool>& vis , bool& ans){
    if(root == 0) return ;
    
    vis[root->data] = 1; 
    if(root->left == 0 && root->right == 0){
        int xp1 = root->data + 1;
        int xn1 = root->data - 1 == 0 ? root->data : root->data - 1;
        if(vis.find(xp1) != vis.end() && vis.find(xn1) != vis.end()){
            ans = true;
            return;
        }
    }
    
    fun(root->left , vis , ans);
    fun(root->right , vis , ans);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    bool ans = false;
    unordered_map<int , bool> vis;
    fun(root , vis , ans);
    return ans;
}