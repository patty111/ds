// @lc app=leetcode id=34 lang=c
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left = 0; 
    int right = numsSize - 1;
    int* ans = (int*)malloc(sizeof(int) * 2);
    ans[0] = -1, ans[1] = -1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else{
            ans[0] = mid;
            ans[1] = mid;
            break;
        }
    }
    while (ans[0] >=1 && nums[ans[0]-1] == target)
        ans[0]--;

    while (ans[1] <= numsSize-2 && nums[ans[1]+1] == target)
        ans[1]++;
    
    *returnSize = 2;    // need to assign
    return ans;
}
// @lc code=end

