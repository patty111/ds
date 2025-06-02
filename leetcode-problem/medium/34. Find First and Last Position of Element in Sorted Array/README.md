## 34. Find First and Last Position of Element in Sorted Array
### 題目
**[link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)**
在不知道 linked list head 和 前一個節點的情況下刪除一個指定節點，指定節點不會是 Tail。
### Solution
直觀是遍歷搜, 但要快所以用binary search. 同時因包含連續的情況, 所以要分別找出first和last的位置。

> O(n)Runtime beats 100%, memory usage beats 93.44
