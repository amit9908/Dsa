class Solution {
public:
    int klengthpref(string arr[], int n, int k, string str) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            string temp = arr[i];
            int j = 0;
            while (j < k) {
                if (str[j] == temp[j]) {
                    j++;
                } else {
                    break;
                }
            }
            if (j == k) {
                count++;
            }
        }
        return count;
    }
};
 t.c o(n*k)
 s.c 0(n*k)