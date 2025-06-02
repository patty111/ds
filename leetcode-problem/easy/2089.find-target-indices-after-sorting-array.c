//  @lc app=leetcode id=2089 lang=c
// @lc code=start
void bsort(int* arr, int arrSize){
    for(int i=0;i<arrSize;i++){
        for(int j=0;j<arrSize-i-1;j++){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize){
    bsort(nums, numsSize);
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
    
    *returnSize = ans[0] == -1 ? 0 : ans[1] - ans[0] + 1;
    int* result = (int*)malloc(sizeof(int) * *returnSize);
    if (*returnSize == 0) return result;
    int index = 0;
    for (int i=ans[0];i<=ans[1];i++){
        result[index++] = i;
    }
    return result;
}
// @lc code=end

