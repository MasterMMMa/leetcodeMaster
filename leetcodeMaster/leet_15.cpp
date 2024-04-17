//Given an integer array nums, return all the triplets[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//
//Notice that the solution set must not contain duplicate triplets.
//
//
//
//Example 1:
//
//Input: nums = [-1, 0, 1, 2, -1, -4]
//Output : [[-1, -1, 2], [-1, 0, 1]]
//Explanation :
//	nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
//	nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
//	nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
//	The distinct triplets are[-1, 0, 1] and [-1, -1, 2].
//	Notice that the order of the output and the order of the triplets does not matter.
//	Example 2:
//
//Input: nums = [0, 1, 1]
//Output : []
//Explanation : The only possible triplet does not sum up to 0.
//Example 3 :
//
//	Input : nums = [0, 0, 0]
//	Output : [[0, 0, 0]]
//	Explanation : The only possible triplet sums up to 0.
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector <vector<int>> v;
        int start;
        int end = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            start = i + 1;
			end = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while (end > start) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == 0) {
                    //cout << "i: " << i << " start: " << start << " end: " << end << endl;
                    v.push_back({nums[i],nums[start],nums[end]});
                    while (start < end && nums[start] == nums[start + 1]) start++; // ?? start ????
                    while (start < end && nums[end] == nums[end - 1]) end--; // ?? end ????
                    start++;
					end--;
                }
                else if (sum > 0) {
                    end--;
                }
                else {
                    start++;
                }
            }
        }
        return v;
    }
};

//int main() {
//    	vector<int> v = { 0,0,0,0 };
//	Solution s;
//    cout << "Solution is: " << endl;
//	vector<vector<int>> v1 = s.threeSum(v);
//    for (int i = 0; i < v1.size(); i++) {
//        for (int j = 0; j < v1[i].size(); j++) {
//			cout << v1[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}