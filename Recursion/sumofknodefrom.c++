 
#include <bits/stdc++.h>
using namespace std;
 
// Structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->data = val;
        this->left = 0;
        this->right = 0;
    }
};
 
// Function for marking the parent node
// for all the nodes using DFS
void dfs(Node* root,
         unordered_map<Node*, Node*>& par)
{
    if (root == 0)
        return;
    if (root->left != 0)
        par[root->left] = root;
    if (root->right != 0)
        par[root->right] = root;
    dfs(root->left, par);
    dfs(root->right, par);
}
 
// Function calling for finding the sum
void dfs3(Node* root, int h, int& sum, int k,
          unordered_map<Node*, int>& vis,
          unordered_map<Node*, Node*>& par)
{
    if (h == k + 1)
        return;
    if (root == 0)
        return;
    if (vis[root])
        return;
    sum += root->data;
    vis[root] = 1;
    dfs3(root->left, h + 1, sum, k, vis, par);
    dfs3(root->right, h + 1, sum, k, vis, par);
    dfs3(par[root], h + 1, sum, k, vis, par);
}
 
// Function for finding
// the target node in the tree
Node* dfs2(Node* root, int target)
{
    if (root == 0)
        return 0;
    if (root->data == target)
        return root;
    Node* node1 = dfs2(root->left, target);
    Node* node2 = dfs2(root->right, target);
    if (node1 != 0)
        return node1;
    if (node2 != 0)
        return node2;
}
 
// Function to find the sum at distance K
int sum_at_distK(Node* root, int target,
                 int k)
{
    // Hash Table to store
    // the parent of a node
    unordered_map<Node*, Node*> par;
 
    // Make the parent of root node as NULL
    // since it does not have any parent
    par[root] = 0;
 
    // Mark the parent node for all the
    // nodes using DFS
    dfs(root, par);
 
    // Find the target node in the tree
    Node* node = dfs2(root, target);
 
    // Hash Table to mark
    // the visited nodes
    unordered_map<Node*, int> vis;
 
    int sum = 0;
 
    // DFS call to find the sum
    dfs3(node, 0, sum, k, vis, par);
    return sum;
}
 
// Driver Code
int main()
{
    // Taking Input
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(19);
    root->right->right->left = new Node(20);
    root->right->right->right
        = new Node(11);
    root->left->left->left->left
        = new Node(30);
    root->left->left->right->left
        = new Node(40);
    root->left->left->right->right
        = new Node(50);
 
    int target = 9, K = 1;
 
    // Function call
    cout << sum_at_distK(root, target, K);
    return 0;
}