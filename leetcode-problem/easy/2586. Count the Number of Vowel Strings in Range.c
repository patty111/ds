#include <string.h>
int is_vowel(char c){
    char* str = "aeiou";
    for (int i=0;i<5;i++)
        if (c == str[i]) return 1;
    return 0;
}

int vowelStrings(char ** words, int wordsSize, int left, int right){
    int count = 0;
    for (int i=left;i<=right;i++){       
        int frontF = 0;
        if (is_vowel(words[i][0]))
            frontF = 1;
        if (is_vowel(words[i][strlen(words[i]) - 1]) && frontF) count++;
    }
    return count;
}
    