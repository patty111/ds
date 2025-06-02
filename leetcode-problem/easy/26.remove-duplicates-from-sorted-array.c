// @lc app=leetcode id=26 lang=c
// @lc code=start
int removeDuplicates(int* nums, int numsSize){
    int k = 0;
    int* flag_location = nums;
    if (numsSize == 1) return 1;
    for (int i=0;i<numsSize-1;i++){
        if (nums[i] != nums[i+1]){
            *(++flag_location) = nums[i+1];
            k++;
        }
    }
    if (nums[numsSize-1] == nums[k]) return k+1;
    return k;
    //nums[numsSize-1] != nums[numsSize-2];  wrong method
}

/*Notes
注意最後比較，因為已經把重複地用後面的位移取代掉，所以應該是
用最後一個跟最後一個不重複的(nums[k])比較
e.g.
[1,2,2,3] ->在最後一圈迭帶: [1,2,3,3]
                                ^
                                k在這邊 
*/
// @lc code=end

