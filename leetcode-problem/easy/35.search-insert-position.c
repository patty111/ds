// @lc app=leetcode id=35 lang=c
// @lc code=start
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target){
            right = mid - 1;
            result = mid;
        }
        else if (nums[mid] < target){
            left = mid + 1;
            result = mid + 1;  // notice the mid+1 part. 因為要往後 "insert", 從右靠近mid本來就是target 右邊, 
            //即insert index.從左邊的話mid所在位置比target 小，要insert 需往後一格，即mid + 1
        }
        else return mid;
    }
    return result;
}
// @lc code=end

