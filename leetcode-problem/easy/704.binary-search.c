//  @lc app=leetcode id=704 lang=c
// @lc code=start
// https://medium.com/appworks-school/binary-search-%E9%82%A3%E4%BA%9B%E8%97%8F%E5%9C%A8%E7%B4%B0%E7%AF%80%E8%A3%A1%E7%9A%84%E9%AD%94%E9%AC%BC-%E4%B8%80-%E5%9F%BA%E7%A4%8E%E4%BB%8B%E7%B4%B9-dd2cd804aee1
int search(int* nums, int numsSize, int target){
    int left = 0; int right = numsSize - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else if (nums[mid] > target) right = mid - 1;
    }
    return -1;
}
// @lc code=end
