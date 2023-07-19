class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int i = 0, j = 1, count = 0;
        while (j < intervals.size()) {
            if (intervals[j][0] < intervals[i][1]) {
                // There is an overlap, so remove one interval.
                count++;
                // Choose the interval with the smaller end point to remove.
                if (intervals[j][1] < intervals[i][1]) {
                    i = j;
                }
                j++;
            } else {
                i = j;
                j++;
            }
        }
        return count;
    }
};