//  @lc app=leetcode id=69 lang=c
// @lc code=start
int mySqrt(int x){
    unsigned int xp = x;
    int result;
    int left = 1, right = x/2;
    if (x <= 1) return x;
    while (left <= right){
        unsigned int mid = left + (right - left) / 2;
        if (mid == xp / mid) return mid;        // mid == xp/mid is used to deal with overflow
        else if (mid < xp / mid){
            left = mid + 1;
            result = mid;
        }
        else if (mid > xp / mid)
            right = mid - 1;
    }
    return result;
}
// @lc code=end

