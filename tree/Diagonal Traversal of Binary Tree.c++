vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   if(root == NULL) return ans;
   
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       Node* temp = q.front();
       q.pop();
       while(temp){
           ans.push_back(temp->data);
           if(temp->left) q.push(temp->left);
          
           temp = temp->right;
       }
   }
   return ans;
}



void recursiveApproach(Node* root, int diagonalDistance, map<int, vector<int>> &mp){
    if(!root)
        return;
    
    mp[diagonalDistance].push_back(root->data);
    
    recursiveApproach(root->left, diagonalDistance + 1, mp);
    recursiveApproach(root->right, diagonalDistance, mp);
}

vector<int> diagonal(Node *root)
{
   // your code here
   map<int, vector<int>> mp;
   vector<int> res;
   recursiveApproach(root, 0, mp);
   
   for(auto i : mp){
        vector<int> x;
        x = i.second;
        for(auto j : x)
            res.push_back(j);
   }
   return res;
}