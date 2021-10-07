# Search In Rotated Sorted Array

There is an integer array nums (with different values) sorted in ascending order. Before being passed to your function, nums may be rotated at an unknown pivot index k (1 <= k <nums.length), so the resulting array is [nums[k], nums[k+1], .. ., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] may rotate at pivot index 3 and become [4,5,6,7,0,1,2]. Given the possible rotated array nums and integer target, if the target is in nums, return the index of the target, if not in nums, return -1. 

You must write an algorithm with a runtime complexity of O(log n).

## Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Explanation: for this example actual array was [0,1,2,4,5,6,7] but after rotating it once we get [1,2,4,5,6,7,0] and with next rotation we get [2,4,5,6,7,0,1] and with next we get [4,5,6,7,0,1,2]

and hence after three rotation we get the arr which is the input, so there can be n times of ratation on the the array.

## Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

## Example 3:
Input: nums = [1], target = 0
Output: -1 
