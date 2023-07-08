class Solution {
public:
    int maxi = 0;
    int n;

    void findMax(string& ak) {
        int len = 0;
        int i = 0;

        while (i < n) {
            if (ak[i] == 'T') {
                len = 1;
                i++;
                while (i < n && ak[i] == 'T') {
                    len++;
                    i++;
                }
                maxi = max(maxi, len);

            } else {
                len = 1;
                i++;
                while (i < n && ak[i] == 'F') {
                    len++;
                    i++;
                }
                maxi = max(maxi, len);
            }
        }
    }

    void solve(string& ak, int k, int idx) {
        findMax(ak);
        if (idx >= n || k == 0) {
            return;
        }

        ak[idx] = ak[idx] == 'T' ? 'F' : 'T';
        solve(ak, k - 1, idx + 1);
        ak[idx] = ak[idx] == 'T' ? 'F' : 'T';

        solve(ak, k, idx + 1);
    }

    int maxConsecutiveAnswers(string ak, int k) {
        n = ak.size();  // Assign the size to the member variable
        solve(ak, k, 0);
        return maxi;
    }
}

// t.c 0(2^n)*n
// s.c 0(n)