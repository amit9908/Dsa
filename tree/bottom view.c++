//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
     vector<int> ans;
     if(root == NULL) return ans;
     map<int , int> bnode;
     
     queue<pair<Node* , int>> q;
     q.push(make_pair(root , 0));
     
     while(!q.empty()){
         pair<Node* , int> temp = q.front();
         q.pop();
         
         Node* fnode = temp.first;
         int hd = temp.second;
         
         bnode[hd] = fnode->data;
         
         if(fnode->left){
             q.push(make_pair(fnode->left , hd-1));
         }
         if(fnode->right){
             q.push(make_pair(fnode->right , hd+1));
          }
          
     }
     for(auto i:bnode){
         ans.push_back(i.second);
     }
     return ans;
    }
};