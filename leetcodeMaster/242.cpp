//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
//
//
//
//Example 1:
//
//Input: s = "anagram", t = "nagaram"
//Output : true
//Example 2 :
//
//	Input : s = "rat", t = "car"
//	Output : false
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26];
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] % 26;
            arr[x] += 1;
        }
        for (int i = 0; i < t.size(); i++) {
            int y = t[i] % 26;
            arr[y] -= 1;
        }
        for (auto i : arr) {
            if (i != 0) return false;
        }
        return true;
    }
};
//
//int main() {
//	Solution s;
//	cout << s.isAnagram("anagram", "nagaram") << endl;
//	cout << s.isAnagram("rat", "car") << endl;
//	return 0;
//}