class node {
public:
    char ch;
    int count;

    node(char c, int cnt) {
        ch = c;
        count = cnt;
    }
};

class compare {
public:
    bool operator()(node a, node b) {
        return a.count < b.count; // corrected comparison operator
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch - 'a']++;
        }

        priority_queue<node, vector<node>, compare> maxHeap;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                node temp(i + 'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";
        while (maxHeap.size() > 1) {
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();

            ans += first.ch;
            ans += second.ch;

            first.count--;
            second.count--;

            if (first.count != 0) {
                maxHeap.push(first);
            }

            if (second.count != 0) {
                maxHeap.push(second);
            }
        }

        if (!maxHeap.empty()) {
            node temp = maxHeap.top();
            if (temp.count == 1) {
                ans += temp.ch;
            } else {
                return "";
            }
        }

        return ans;
    }
};

The time complexity of the reorganizeString function is O(n) bcoz it is primarily determined by the operations performed within the function.

Frequency Counting: The first loop iterates through the input string s and counts the frequency of each character. This step has a time complexity of O(n), where n is the length of the string.

Building the Priority Queue: The second loop creates a priority queue and inserts nodes representing characters and their frequencies. Since there are 26 characters in the English alphabet, the loop has a constant time complexity of O(26).

Reorganizing the String: The main part of the function involves repeatedly extracting the two nodes with the highest frequencies from the priority queue, updating their counts, and appending the characters to the result string. This process continues until the priority queue has only one element left. Since the size of the priority queue is at most 26, this step has a time complexity of O(26 * log(26)) ≈ O(1) due to the constant number of elements.

Overall, the time complexity of the reorganizeString function is dominated by the frequency counting step, which is O(n). The rest of the operations have constant time complexity. Therefore, the overall time complexity of the function is O(n)