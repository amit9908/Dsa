void printCorner(Node *root)
{

// Base case
if(root==NULL){
    return;
  }
  queue<Node *> q;
  q.push(root);
  while(!q.empty()){
      int count=q.size();
      for(int i=0;i<count ;i++){
          Node *current=q.front();
          q.pop();
          if(i==0 || i==count-1){
              cout<<current->data<<" ";
          }
          if(current->left){
              q.push(current->left);
          }
          if(current->right){
              q.push(current->right);
          }
      }
  }
}