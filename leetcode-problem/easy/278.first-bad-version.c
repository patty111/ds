//  @lc app=leetcode id=278 lang=c
// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n){
    int left = 1, right = n;
    if (isBadVersion(1)) return 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (!isBadVersion(mid))
            left = mid + 1;
        else if (isBadVersion(mid) && isBadVersion(mid-1))
            right = mid - 1;
        else return mid;        
    }
    return 0;
}
// @lc code=end

