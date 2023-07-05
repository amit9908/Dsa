
    class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackSize = haystack.size();
        int needleSize = needle.size();

        if (needleSize == 0) {
            return 0; // Edge case: needle is empty, so it is always found at index 0
        }

        if (haystackSize < needleSize) {
            return -1; // Edge case: haystack is smaller than needle, so needle cannot be found
        }

        for (int i = 0; i <= haystackSize - needleSize; i++) {
            int j;
            for (j = 0; j < needleSize; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }

            if (j == needleSize) {
                return i; // Needle found at index i
            }
        }

        return -1; // Needle not found
    }
};