Node* balancedBst( int s , int e , vector<int>& inorder){
    if(s > e){
        return NULL;
    }
    int mid = s+(e-s)/2;
    Node* root = new Node(inorder[mid]);
    root->left = balancedBst(s , mid-1 , inorder);
    root->right = balancedBst(mid+1 , e , inorder);
    return root;
}
void inorderTraversal(Node* root , vector<int>& inorder){
    if(!root) return;
    
    inorderTraversal(root->left , inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right , inorder);
    
    return;
}
Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> inorder;
	inorderTraversal(root , inorder);
	int start = 0;
	int end = inorder.size()-1;
	Node* ans = balancedBst(start , end ,inorder);
	return ans;
}