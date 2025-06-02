 // @lc app=leetcode id=28 lang=c
 // @lc code=start
#include <string.h>
int strStr(char* haystack, char* needle){
    int index = 0;
    while (*haystack != '\0'){
        if (strncmp(haystack, needle, strlen(needle)) == 0)
            return index;
        else{
            haystack++;
            index++;
        }
    }
    return -1;
}
// @lc code=end

