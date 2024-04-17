//Given an integer array nums and an integer val, remove all occurrences of val in nums in - place.The order of the elements may be changed.Then return the number of elements in nums which are not equal to val.
//
//Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things :
//
//Change the array nums such that the first k elements of nums contain the elements which are not equal to val.The remaining elements of nums are not important as well as the size of nums.
//Return k.

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pt1{ 0 }, pt2{ 0 };
        int size = nums.size();
        int counter = 0;
        for (int i = 0; i < size; i++) {
            if (nums[pt1] != val) {
                nums[pt2] = nums[pt1];
                pt2++;
                counter++;
            }
            pt1++;
        }
        return counter;
    }
};

//int main() {
//    Solution sol;
//    vector<int> nums = { 3, 2, 2, 3 };
//    int val = 3;
//    //test case 1
//    int result = sol.removeElement(nums, val);
//    cout << "Test case 1: " << result << endl;
//    return 0;
//}