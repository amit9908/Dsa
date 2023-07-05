        int i = 0, j = m - 1, ans = -1;
        while (i < n && j >= 0) {
            if (arr[i][j] == 1) {
                ans = i;
                j--;
            } else i++;
        }
        return ans;
    }