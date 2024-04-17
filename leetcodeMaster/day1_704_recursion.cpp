//704. Binary Search
//Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.If target exists, then return its index.Otherwise, return -1.
//
//You must write an algorithm with O(log n) runtime complexity.
//
//
//
//Example 1:
//
//Input: nums = [-1, 0, 3, 5, 9, 12], target = 9
//Output : 4
//Explanation : 9 exists in nums and its index is 4
//Example 2 :
//
//	Input : nums = [-1, 0, 3, 5, 9, 12], target = 2
//	Output : -1
//	Explanation : 2 does not exist in nums so return -1

#include <vector>
#include <iostream>

using namespace std;

//the simplest approach to search a target is the brute force approach to iterate the array and find the target with O(n) time complexity
//binary serach is a divide and conquer algorithm that has O(log n) time complexity
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;//empty vector
        int start = 0;
        int end = nums.size() - 1;
        int sol = helper_binaryserach(nums, target, start, end);
        return sol;

    }

    int helper_binaryserach(vector<int>& nums, int target, int start, int end) {
        //logic behind the target not in the vector is that the start and end will cross each other
        if (start > end) return -1;
        int mid = (start + end) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) return helper_binaryserach(nums, target, start, mid - 1);
        if (nums[mid] < target) return helper_binaryserach(nums, target, mid + 1, end);
    }
};

//int main() {
//    Solution s;
//    vector<int> v { -1, 0, 3, 5, 9, 12 };
//    int target = 9;
//    int sol = s.search(v, target);
//    cout << sol << endl;
//    return 0;
//}

