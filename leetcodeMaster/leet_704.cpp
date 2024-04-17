//Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.If target exists, then return its index.Otherwise, return -1.
//
//You must write an algorithm with O(log n) runtime complexity.

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while (right >= left) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) right = mid - 1;
            if (nums[mid] < target) left = mid + 1;
        }
        return -1;
    }
};