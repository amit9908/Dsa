class NodeData {
public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData() {
        size = 0;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        validBST = true;
    }

    NodeData(int size, int min, int max, bool valid) {
        this->size = size;
        minVal = min;
        maxVal = max;
        validBST = valid;
    }
};

NodeData find(Node* root, int& ans) {
    if (!root) {
        NodeData temp;
        return temp;
    }

    NodeData left = find(root->left, ans);
    NodeData right = find(root->right, ans);

    NodeData currNode;
    currNode.size =  
    if (left.validBST && right.validBST && root->data > left.maxVal && root->data < right.minVal) {
        currNode.validBST = true;
    } else {
        currNode.validBST = false;
    }

    if (currNode.validBST) {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

class Solution {
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node* root) {
        int ans = 0;
        find(root, ans);
        return ans;
    }
};
