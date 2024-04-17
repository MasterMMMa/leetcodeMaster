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
        int fast = 0, slow = 0, counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[slow] = nums[fast];
                slow++;
                counter++;
            }
            fast++;
        }
        return counter;
    }
};

//int main() {
//    Solution s;
//    vector<int> v{ 3, 2, 2, 3 };
//    int val = 3;
//    int sol = s.removeElement(v, val);
//    cout << sol << endl;
//    //print the vector
//    for (int i = 0; i < sol; i++) {
//		cout << v[i] << " ";
//	}
//    return 0;
//}