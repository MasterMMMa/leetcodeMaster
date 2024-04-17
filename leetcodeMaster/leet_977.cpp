//Given an integer array nums sorted in non - decreasing order, return an array of the squares of each number sorted in non - decreasing order.

//Given an integer array nums sorted in non - decreasing order, return an array of the squares of each number sorted in non - decreasing order.

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums.empty()) return nums;
        if (nums.size() == 1) {
            nums[0] = nums[0] * nums[0];
            return nums;
        }
        int x = 0;
        int y = nums.size() - 1;//two pointer
        int index = y;
        vector<int> sol(index + 1, 0);
        while (x <= y) {
            if (abs(nums[x]) > abs(nums[y])) {
                sol[index] = nums[x] * nums[x];
                x++;
            }
            else {
                sol[index] = nums[y] * nums[y];
                y--;
            }
            index--;
        }
        return sol;
    }
};