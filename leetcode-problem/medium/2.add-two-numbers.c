 // @lc app=leetcode id=2 lang=c
 // @lc code=start

#include <stdlib.h>
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

void printAll(struct ListNode* linkedList){
    struct ListNode* cursor = linkedList;
    if (cursor == NULL)
        printf("Nothing in list...\n");
    else

        for (;cursor != NULL; cursor = cursor->next)
            printf("%d - ",cursor->val);
        printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    struct ListNode* ptr1 = l1;
    struct ListNode* ptr2 = l2;
    struct ListNode* resultHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* resultcursor = resultHead;
    resultcursor->next = NULL;

    // while(1){
        resultcursor->val = ptr1->val + ptr2->val;
        if ((ptr1->val + ptr2->val) >= 10){
            carry = 1;
            resultcursor->val -= 10;
        }
        resultcursor->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        resultcursor = resultcursor->next;
        resultcursor->next = NULL;

//         if (ptr1->next)
//             ptr1 = ptr1->next;
//         else
//             ptr1->val = 0;

//         if (ptr2->next)
//             ptr2 = ptr2->next;
//         else
//             ptr2->val = 0;

//         if (!ptr1 && !ptr2) {
//             resultcursor = NULL;
//             return resultHead;
//         }
//     }
// }



int main(){
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l1H = l1;
    struct ListNode* l2H = l2;
    l1H->val = 2;
    l1H->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1H = l1H->next;
    l1H->val = 4;
    l1H->next = NULL;
    l1H->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1H = l1H->next;
    l1H->val = 3;
    l1H->next = NULL;


    l2H->val = 5;
    l2H->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2H = l2H->next;
    l2H->val = 6;
    l2H->next = NULL;
    l2H->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2H = l2H->next;
    l2H->val = 4;
    l2H->next = NULL;





    struct ListNode* res = addTwoNumbers(l1,l2);

}

// @lc code=end

