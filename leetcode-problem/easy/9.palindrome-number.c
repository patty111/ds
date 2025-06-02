/*
 * @lc app=leetcode id=9 lang=c
 */


bool isPalindrome(int x){
    if (x < 0) return false;
    if (x == 0) return true;

    int recordArr[10];
    int digitCount = 0;
    while (1){
        recordArr[digitCount++] = x % 10;
        x = (int)x/10;
        if (!x) break;
    }
    for(int i=0;i<digitCount/2;i++){
        if (recordArr[i] == recordArr[digitCount-i-1]) continue;
        else return false;
    }
    return true;
}
