//Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples(i, j, k, l) such that :
//
//0 <= i, j, k, l < n
//	nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
//
//
//	Example 1:
//
//Input: nums1 = [1, 2], nums2 = [-2, -1], nums3 = [-1, 2], nums4 = [0, 2]
//Output : 2
//Explanation :
//	The two tuples are :
//1. (0, 0, 0, 1)->nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0)->nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        for (auto i : nums1) {
            for (auto j : nums2) {
                map[i + j] += 1;
            }
        }
        int counter = 0;
        for (auto i : nums3) {
            for (auto j : nums4) {
                int num = i + j;
                if (map.find(0 - num) != map.end()) {
                    counter += map[0 - num];
                }
            }
        }
        return counter;
    }
};

//int main() {
//    Solution s;
//    vector<int> nums1 = { 1, 2 };
//    vector<int> nums2 = { -2, -1 };
//    vector<int> nums3 = { -1, 2 };
//    vector<int> nums4 = { 0, 2 };
//    cout << s.fourSumCount(nums1, nums2, nums3, nums4) << endl;
//    return 0;
//}