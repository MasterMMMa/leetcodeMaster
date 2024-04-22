//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//You can return the answer in any order.
//Example 1:
//
//Input: nums = [2, 7, 11, 15], target = 9
//Output : [0, 1]
//Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].
//Example 2 :
//
//	Input : nums = [3, 2, 4], target = 6
//	Output : [1, 2]
//	Example 3 :
//
//	Input : nums = [3, 3], target = 6
//	Output : [0, 1]
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//if I use brute force I will have to use two loops to find the solution, with time complexity of O(n^2)
//use unordered_map to store the index of the element and the element itself,   i can get time complexity of O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 0) return nums;
        vector<int> sol;
        unordered_map<int, int> map;//first element is value, second is index;
        // not necessray to use extra loop to add element in map
        //for (int i = 0; i < nums.size(); i++) {
        //    map[nums[i]] = i;
        //}
        for (int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            if (map.find(num) != map.end()) {
                sol.push_back(i);
                sol.push_back(map[num]);
                return sol;
            }
            map[nums[i]] = i;
        }
        return sol;
    }
};