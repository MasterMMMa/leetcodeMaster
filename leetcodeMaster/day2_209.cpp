//Given an array of positive integers nums and a positive integer target, return the minimal length of a
//subarray
//whose sum is greater than or equal to target.If there is no such subarray, return 0 instead.
//
//
//
//Example 1:
//
//Input: target = 7, nums = [2, 3, 1, 2, 4, 3]
//Output : 2
//Explanation : The subarray[4, 3] has the minimal length under the problem constraint.
//Example 2 :
//
//    Input : target = 4, nums = [1, 4, 4]
//    Output : 1

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//brute froce 是两个for loop全部比较一遍
//第一次解决问题是没有认真分析需求，忽略了应该是连续的subarray。*注意认真理解问题*
//大致连接sliding window 思路之后实现过程忘了取subarray长度时因为index是0开始的所以 需要i - start +1
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int start = 0, sum = 0;
        int minLen = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (target <= sum) {
                //cout << "yeah" << "target : " << target << "sum: " << sum<< endl;
                minLen = min(minLen, i - start);
                sum -= nums[start];
                start++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

//int main() {
//    Solution s;
//    vector<int> v{ 1,3,4,5,6 };//[12,28,83,4,25,26,25,2,25,25,25,12]
//    int target = 10;
//    int i = s.minSubArrayLen(target, v);
//    cout << i;
//}