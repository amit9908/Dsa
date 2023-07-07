class node{
    public:
    char data;
    int count;
    node(char ch,int c){
        data = ch;
        count = c; 
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->count < b->count;
    }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<node*, vector<node*>,compare>maxHeap;

        if(a > 0){
            node* temp = new node('a',a);
            maxHeap.push(temp);
        }
        if(b > 0){
            node* temp = new node('b',b);
            maxHeap.push(temp);
        }
        if(c > 0){
            node* temp = new node('c',c);
            maxHeap.push(temp);
        }

        string ans = "";

        while(maxHeap.size() > 1){
            node* first = maxHeap.top();
            maxHeap.pop();
            node* second = maxHeap.top();
            maxHeap.pop();

            if(first->count >= 2){
                ans += first->data;
                ans += first->data;
                first->count -= 2;
            }
            else{
                ans += first->data;
                first->count--;
            }
            if(second->count >= first->count && second->count >= 2){
                ans += second->data;
                ans += second->data;
                second->count -= 2;
            }
            else{
                ans += second->data;
                second->count--;
            }

            if(first->count > 0){
                maxHeap.push(first);
            }
            if(second->count > 0){
                maxHeap.push(second);
            }
        }

        if(maxHeap.size() == 1){
            node* temp = maxHeap.top();
            maxHeap.pop();
            if(temp->count >= 2){
                ans += temp->data;
                ans += temp->data;
                temp->count -= 2;
            }
            else{
                ans += temp->data;
                temp->count--;
            }
        }

        return  ans;
    }
};


Building the priority queue: The code inserts a, b, and c elements into the priority queue. Each insertion takes O(log n) time, where n is the number of elements in the priority queue. Since there are at most three elements being inserted, this step takes O(log 3) ≈ O(1) time.

Removing elements from the priority queue: The code repeatedly removes the top two elements from the priority queue until there is at most one element left. The number of iterations required is at most n/2, where n is the total number of elements inserted into the priority queue. Therefore, this step takes O(n/2) ≈ O(n) time.

Constructing the answer string: In each iteration, the code appends characters to the ans string based on the counts of the selected nodes. This step takes constant time for each iteration, which is O(1) per iteration.

Considering the dominant factor, the overall time complexity is O(n), where n is the sum of a, b, and c