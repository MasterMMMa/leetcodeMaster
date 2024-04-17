//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
//
//
//
//Example 1:
//
//Input: nums = [1, 5, 11, 5]
//Output : true
//Explanation : The array can be partitioned as[1, 5, 5] and [11].
//Example 2 :
//
//	Input : nums = [1, 2, 3, 5]
//	Output : false
//	Explanation : The array cannot be partitioned into equal sum subsets.

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) {
			sum += i;
		}
        int target = sum / 2;
        if (target * 2 != sum) return false;
        

    }
};