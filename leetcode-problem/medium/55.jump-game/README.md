## 34. Find First and Last Position of Element in Sorted Array
### 題目
**[link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)**
給定一個已排序的整數陣列 `nums` 和一個目標值 `target`，找出 `target` 在 `nums` 中的起始和結束位置。如果 `target` 不存在於陣列中，返回 `[-1, -1]`。

### Solution
Greedy
1. 用一個maximum存目前可以到達最遠的idx
2. 遍歷所有nums, 檢查maximum是否大於等於i, 表示jump的方法是否可以到達目前的index.

> O(n)Runtime beats 89.98%, memory usage beats 94.33%
