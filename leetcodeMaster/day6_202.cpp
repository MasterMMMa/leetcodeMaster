//Write an algorithm to determine if a number n is happy.
//
//A happy number is a number defined by the following process :
//
//Starting with any positive integer, replace the number by the sum of the squares of its digits.
//Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
//Those numbers for which this process ends in 1 are happy.
//Return true if n is a happy number, and false if not.
//
//
//
//Example 1:
//
//Input: n = 19
//Output : true
//Explanation :
//	1^2 + 9^2 = 82
//	8^2 + 2^2 = 68
//	6^2 + 8^2 = 100
//	1^2 + 0^2 + 0^2 = 1

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

//for each int is ether will be a inifinate loop or it will ends with number equall to 1
//for each iteration I can store the processed number into a set can keep check if it occoured in previous cycle 

//step 1: perform modulo operation to set each num
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        bool flag = true;
        int num = n;
        while (flag) {
            num = getsqr(num);
            if (num == 1) return true;
            if (s.find(num) != s.end()) {
                return false;
            }
            s.insert(num);
            
        }
        return false;

    }

    int getsqr(int n) {
        int happy = 0;
        while (n / 10 > 0) {
            happy += (n % 10) * (n % 10);
            n /= 10;
        }
        happy += (n % 10) * (n % 10);
        return happy;
    }

};

int main() {
    Solution s;
    int i = 100;
    cout << s.isHappy(i);
    return 0;
}