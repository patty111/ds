// @lc app=leetcode id=13 lang=c
// @lc code=start
#include <stdio.h>
#include <string.h>
int convert(char letter){
    switch (letter){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

/* first time implementation
int romanToInt(char* s){
    int numLen = strlen(s); // 7
    int* arr = (int*)malloc(sizeof(int) * numLen);
    for (int i=0;i<numLen;i++)
        arr[i] = convert(s[i]);


    int resultNum = 0;
    int temp = 0;
    if (numLen > 1){
        if (arr[0] >= arr[1])
            resultNum = arr[0];
    }else resultNum = arr[0];

    for (int i=1;i<numLen;i++){
        if (arr[i] == arr[i-1])
            resultNum += arr[i];
        else if (arr[i] > arr[i-1])
            resultNum += (arr[i] - arr[i-1]);
        else if (i != numLen-1 && arr[i] < arr[i+1])
            continue;
        else resultNum += arr[i];
    }
    return resultNum;
}
*/

// better thought
int romanToInt(char* s){
    int result = 0;
    for (int i=0;i<strlen(s);i++){
        if (convert(s[i]) < convert(s[i+1]))
            result -= convert(s[i]);
        else result += convert(s[i]);
    }
    return result;
}


// @lc code=end

