//@lc app=leetcode id=27 lang=c
// @lc code=start
int removeElement(int* nums, int numsSize, int val){
    if (numsSize == 0) return 0;
    int fast = 0, slow = 0, count = 0;
    while(fast < numsSize){
        if (nums[fast] == val)
            count++;
        else
            nums[slow++] = nums[fast];
        fast++;
    }
    return numsSize-count;
}
// @lc code=end

