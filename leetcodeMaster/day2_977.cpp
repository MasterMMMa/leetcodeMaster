//Given an integer array nums sorted in non - decreasing order, return an array of the squares of each number sorted in non - decreasing order.
//
//
//
//Example 1:
//
//Input: nums = [-4, -1, 0, 3, 10]
//Output : [0, 1, 9, 16, 100]
//Explanation : After squaring, the array becomes[16, 1, 0, 9, 100].
//After sorting, it becomes[0, 1, 9, 16, 100].

#include <vector>
#include <algorithm>
#include <iostream>
#include  <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums.size() == 0) return nums;
        int start = 0, end = nums.size() -1;
        vector<int> v;// unnecessary, can direct push_back to sol from the end to start
        vector<int> sol;
        while (end >= start) {
            bool b = abs(nums[start]) > abs(nums[end]);
            int big = b ? abs(nums[start]) : abs(nums[end]);
            v.push_back(big);
            if (b) start++;
            else end--;
        }
        /*for (auto i : v) {
            cout << i << "  ";
        }*/
        for (int i = v.size() - 1; i >= 0; i--) {
            sol.push_back(v[i] * v[i]);
        }
        return sol;
    }
};

//int main() {
//    Solution s;
//    vector<int> v{ -7, -5,0,1,9,10 };
//    vector<int> v1 = s.sortedSquares(v);
//    return 0;
//}