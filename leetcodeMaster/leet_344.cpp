//Write a function that reverses a string.The input string is given as an array of characters s.
//
//You must do this by modifying the input array in - place with O(1) extra memory.
//
//
//
//Example 1:
//
//Input: s = ["h", "e", "l", "l", "o"]
//Output : ["o", "l", "l", "e", "h"]
//Example 2 :
//
//	Input : s = ["H", "a", "n", "n", "a", "h"]
//	Output : ["h", "a", "n", "n", "a", "H"]

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 0 && s.size() == 1) return;
        int size = s.size();
        int start = 0;
        int end = size - 1;
        while (end > start) {
            cout << "start: " << start << " end: " << end << endl;
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            cout << "start: " << start << " end: " << end << endl;
            start++;
            end--;
        }
    }
};

//int main() {
//    	Solution sol;
//	vector<char> s = { 'h', 'e', 'l', 'l', 'o' };
//	sol.reverseString(s);
//    cout<< "Reversed string: " ;
//    for (auto c : s) {
//		cout << c << " ";
//	}
//	return 0;
//}