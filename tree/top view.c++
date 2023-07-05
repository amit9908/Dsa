class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
    vector<int> ans;
    if(root == NULL) return ans;
    
    map<int,int> tNode;
    queue<pair<Node* , int>> q;
    
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node* , int> temp = q.front();
        q.pop();
        
        Node* fnode = temp.first;
        int hd = temp.second;
        
        if(tNode.find(hd) == tNode.end()){
            tNode[hd] = fnode->data;
        }
        if(fnode->left){
            q.push(make_pair(fnode->left , hd-1));
        }
        if(fnode->right){
            q.push(make_pair(fnode->right ,hd+1));
        }
    }
    for(auto i:tNode){
        ans.push_back(i.second);
    }
    return ans;
    }

};
