class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int big = nums[0];
        int small = nums[0];
        if (nums.size() <= 2)
                return -1;
        for (int i=1; i<nums.size(); ++i){
            big = max(big, nums[i]);
            small = min(small, nums[i]);
        }
        for (int i=0; i<nums.size(); ++i){
            
            if (nums[i] != small && nums[i] != big)
                return nums[i];
        }
        return -1;
    }
};