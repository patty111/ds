// @lc app=leetcode id=70 lang=c
// @lc code=start
int climbStairs(int n){
    if (n == 1) return 1;
    int* record = (int*)malloc(sizeof(int) * n);
    record[0] = 1;
    record[1] = 2;
    for (int i=2;i<n;i++)
        record[i] = record[i-1] + record[i-2];
    return record[n-1];
}
// @lc code=end

