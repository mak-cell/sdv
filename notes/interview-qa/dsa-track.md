# DSA track (light): weeks 9 to 26

Goal: be comfortable with Google-style coding rounds for embedded roles. Solve in **C first**, then C++ when you reach week 17.

**When:** the Tue and Thu 21:30 coding blocks from week 9 (22 Dec) switch from build work to DSA. That is 2 problems per block, 4 per week. Build work moves fully to Saturday. Total time stays about 10 hours a week.

**How to solve each problem (20 minutes max):**
1. Say the brute force out loud and its Big-O.
2. Find the better idea (the week's pattern). Write it in C.
3. Test edge cases: empty input, one element, max values, negatives.
4. If stuck at 20 minutes, read the solution, then redo it from scratch the next day. Log it in `mistakes/dsa-log.md`.

**Checkpoints:**
- Mock interview 1: Sun 20 Dec 2026 (end of month 2): C, MCU, RTOS, CAN.
- Mock interview 2: Sun 14 Feb 2027 (end of month 4): AUTOSAR, UDS, Linux, plus 1 DSA problem live.

| Week | Starts | Pattern | Problems |
|---|---|---|---|
| 9 | 21 Dec | Bit manipulation | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) · [Reverse Bits](https://leetcode.com/problems/reverse-bits/) · [Power of Two](https://leetcode.com/problems/power-of-two/) · [Single Number](https://leetcode.com/problems/single-number/) |
| 10 | 28 Dec | Arrays | [Two Sum](https://leetcode.com/problems/two-sum/) · [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) · [Move Zeroes](https://leetcode.com/problems/move-zeroes/) · [Rotate Array](https://leetcode.com/problems/rotate-array/) |
| 11 | 04 Jan | Strings | [Reverse String](https://leetcode.com/problems/reverse-string/) · [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) · [Valid Anagram](https://leetcode.com/problems/valid-anagram/) · [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) |
| 12 | 11 Jan | Hash maps | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) · [Group Anagrams](https://leetcode.com/problems/group-anagrams/) · [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) · [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) |
| 13 | 18 Jan | Two pointers | [Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) · [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) · [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) · [3Sum](https://leetcode.com/problems/3sum/) |
| 14 | 25 Jan | Sliding window | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) · [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) · [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) · [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) |
| 15 | 01 Feb | Linked lists | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) · [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) · [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) · [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) |
| 16 | 08 Feb | Stacks, queues, ring buffers | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) · [Min Stack](https://leetcode.com/problems/min-stack/) · [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/) · [Design Circular Queue](https://leetcode.com/problems/design-circular-queue/) |
| 17 | 15 Feb | Binary search | [Binary Search](https://leetcode.com/problems/binary-search/) · [Search Insert Position](https://leetcode.com/problems/search-insert-position/) · [Find Peak Element](https://leetcode.com/problems/find-peak-element/) · [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) |
| 18 | 22 Feb | Trees I | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) · [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) · [Same Tree](https://leetcode.com/problems/same-tree/) · [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) |
| 19 | 01 Mar | Trees II (BST) | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) · [Lowest Common Ancestor of a BST](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) · [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) · [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) |
| 20 | 08 Mar | Heaps and intervals | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/) · [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) · [Merge Intervals](https://leetcode.com/problems/merge-intervals/) · [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) |
| 21 | 15 Mar | Matrix and bits II | [Counting Bits](https://leetcode.com/problems/counting-bits/) · [Rotate Image](https://leetcode.com/problems/rotate-image/) · [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) · [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) |
| 22 | 22 Mar | Graphs (BFS/DFS) | [Flood Fill](https://leetcode.com/problems/flood-fill/) · [Number of Islands](https://leetcode.com/problems/number-of-islands/) · [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) · [Course Schedule](https://leetcode.com/problems/course-schedule/) |
| 23 | 29 Mar | Dynamic programming basics | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) · [House Robber](https://leetcode.com/problems/house-robber/) · [Coin Change](https://leetcode.com/problems/coin-change/) · [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) |
| 24 | 05 Apr | Design problems | [Design HashSet](https://leetcode.com/problems/design-hashset/) · [Design Circular Deque](https://leetcode.com/problems/design-circular-deque/) · [LRU Cache](https://leetcode.com/problems/lru-cache/) · [Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) |
| 25 | 12 Apr | Review | Redo 2 problems from your DSA mistakes log · Redo 2 more from the mistakes log |
| 26 | 19 Apr | Timed practice | Timed: 2 mediums in 45 minutes (pick from weeks 13-24) · Timed: 2 more mediums in 45 minutes |
