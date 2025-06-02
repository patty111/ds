int lengthOfLIS(int* arr, int len) {
    int* tails = (int*)malloc(len * sizeof(int));
    int max_len = 1;
    tails[0] = arr[0];

    for (int i=1; i<len; i++) {
        if (arr[i] < tails[0]) {
            tails[0] = arr[i];
        }
        else if (arr[i] > tails[max_len-1]) {
            tails[max_len] = arr[i];
            max_len++;
        }
        else {
            int idx = binarySearch(tails, -1, max_len-1, arr[i]); // find the index of the smallest element in tails that is greater than or equal to arr[i]
            tails[idx] = arr[i]; // replace tails[idx] with arr[i]
        }
    }

    free(tails);
    return max_len;
}

int binarySearch(int* arr, int l, int r, int x) {
    while (r-l > 1) {
        int mid = l + (r-l)/2;
        if (arr[mid] >= x) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    return r;
}